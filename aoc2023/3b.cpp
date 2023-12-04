#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char buffer[420];

const int DAY = 3;
const int PUZZLE_PART = 2;

void download() {
    sprintf(buffer, "sh download.sh %d", DAY);
    system(buffer);
}

void submit(int answer) {
    sprintf(buffer, "sh submit.sh %d %d %d", DAY, PUZZLE_PART, answer);
    system(buffer);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    download();

    ifstream fin(to_string(DAY) + "input.txt");
    int out = 0;

    string str;
    vector<string> vs;
    map<pii, pii> m;
    while (fin >> str) {
        vs.push_back(str);
    }
    rep(i, 0, sz(vs)) {
        rep(j, 0, sz(vs[i])) {
            char c = vs[i][j];
            if (isdigit(c)) {
                int x2 = max(0, i - 1);
                int x1 = min(sz(vs) - 1, i + 1);
                int y1 = min(sz(vs[i]) - 1, j + 1);
                int y2 = max(0, j - 1);
                vector<pii> vc = {{x2, y2}, {x1, y2}, {x2, y1}, {x1, y1}, {i, y1}, {i, y2}, {x1, j}, {x2, j}};
                for (auto& cv : vc) {
                    if (!isdigit(vs[cv.first][cv.second]) && vs[cv.first][cv.second] != '.') {
                        int k = j;
                        string s = "";
                        while (k >= 0 && isdigit(vs[i][k])) {
                            s = vs[i][k] + s;
                            vs[i][k] = '.';
                            k--;
                        }
                        k = j + 1;
                        while (k < sz(vs[i]) && isdigit(vs[i][k])) {
                            s += vs[i][k];
                            vs[i][k] = '.';
                            k++;
                        }
                        // out += stoi(s);
                        if (m.count({cv.first, cv.second})) {
                            m[{cv.first, cv.second}] = {m[{cv.first, cv.second}].first+1, m[{cv.first, cv.second}].second *= stoi(s)};
                        } else {
                            m[{cv.first, cv.second}] = {1, stoi(s)};
                        }
                    }
                }
            }
        }
    }

    for (auto& x : m) {
        if (x.second.first == 2) {
            out += x.second.second;
        }
    }

    cout << out << '\n';

    submit(out);
}