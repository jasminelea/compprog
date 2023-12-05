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
const int PUZZLE_PART = 1;

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
    vector<ll> seeds;

    getline(fin, s);
    stringstream sin(s);
    string ss;
    sin >> ss;
    ll n;
    while (sin >> n) {
        seeds.push_back(n);
    }
    getline(fin, s);
    getline(fin, s);

    vector<vector<vector<ll>>> maps;
    int i = 0;
    maps.emplace_back();
    while (getline(fin, s)) {
        if (!isdigit(s[0])) {
            i++;
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
        for (auto& y : seeds) {
            for (auto& x : m) {
                if (y >= x[1] && y < x[1] + x[2]) {
                    y += x[0] - x[1];
                    break;
                }
            }
        }
    }

    sort(all(seeds));
    out = seeds[0];

    cout << out << '\n';

    submit(out);
}