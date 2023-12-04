
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ifstream fin("input.txt");
    map<string, int> words = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    string s;
    ll out = 0;
    while (fin >> s) {
        string rs = s;
        reverse(all(rs));
        int first = sz(s);
        int last = -1;
        int fv, lv;
        for (auto x : words) {
            int res = s.find(x.first);
            if (res != string::npos) {
                if (res < first) {
                    first = res;
                    fv = x.second;
                }

                string rx = x.first;
                reverse(all(rx));
                res = rs.find(rx);
                res = sz(s) - res - sz(rx);
                if (res > last) {
                    last = res;
                    lv = x.second;
                }
            }
        }
        for (int i = 0; i < first; i++) {
            if (isdigit(s[i])) {
                fv = s[i] - '0';
                break;
            }
        }
        for (int i = sz(s) - 1; i > last; i--) {
            if (isdigit(s[i])) {
                lv = s[i] - '0';
                break;
            }
        }
        out += fv * 10 + lv;
    }
    cout << out;
}