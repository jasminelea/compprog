#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ifstream fin("input.txt");
    string s;
    ll out = 0;
    while (fin >> s) {
        vector<char> v;
        for (auto x : s) {
            if (isdigit(x)) {
                v.push_back(x);
            }
        }
        string str = "";
        str += v[0];
        str += v[sz(v) - 1];
        int num = stoi(str);
        out += num;
    }
    cout << out;
}