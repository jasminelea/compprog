#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char buffer[420];

const int DAY = 5;
const int PUZZLE_PART = 2;

void download() {
    sprintf(buffer, "sh download.sh %d", DAY);
    system(buffer);
}

void submit(ll answer) {
    sprintf(buffer, "sh submit.sh %d %d %lli", DAY, PUZZLE_PART, answer);
    system(buffer);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // download();

    ifstream fin(to_string(DAY) + "input.txt");
    ll out = 0;
    string s;
    vector<vector<ll>> seeds;

    getline(fin, s);
    stringstream sin(s);
    string ss;
    sin >> ss;
    ll n, nn;
    while (sin >> n) {
        sin >> nn;
        seeds.push_back({n, nn});
    }
    getline(fin, s);
    getline(fin, s);

    vector<vector<vector<ll>>> maps;
    int i = 0;
    maps.emplace_back();
    while (getline(fin, s)) {
        if (!isdigit(s[0])) {
            i++;
            // vector<vector<ll>> v;
            // maps.push_back(v);
            getline(fin, s);
            maps.emplace_back();
            continue;
        }
        stringstream sin(s);
        ll a, b, c;
        while (sin >> a >> b >> c) {
            maps[i].push_back({a, b, c});
        }
    }

    for (auto& m : maps) {
        vector<vector<ll>> processed;
        for (auto& x : m) {
            for (int i = 0; i < sz(seeds);) {
                auto y = seeds[i];
                ll ystart = y[0], yend = y[0] + y[1], xstart = x[1], xend = x[1] + x[2];
                ll intersectstart = max(ystart, xstart);
                ll intersectend = min(yend, xend);
                if (intersectend > intersectstart) {
                    seeds.erase(seeds.begin() + i);
                    processed.push_back({intersectstart + x[0] - x[1], intersectend - intersectstart});
                    if (intersectstart > ystart) {
                        seeds.push_back({ystart, intersectstart - ystart});
                    }
                    if (intersectend < yend) {
                        seeds.push_back({intersectend, yend - intersectend});
                    }
                } else {
                    i++;
                }
            }
        }
        seeds.insert(seeds.end(), all(processed));
    }

    sort(all(seeds));
    out = seeds[0][0];

    cout << out << '\n';

    submit(out);
}