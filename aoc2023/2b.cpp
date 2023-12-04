#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int DAY = 2;
const int PUZZLE_PART = 2;

char buffer[420];

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

    // download();

    ifstream f(to_string(DAY) + "input.txt");

    int answer = 0;
    int a, b, x, y, z;
    char c, d;
    string s1, s2, s3, s4;
    stringstream ss;

    int i = 1;

    while (getline(f, s1)) {
        s1 = s1.substr(s1.find(':') + 1, sz(s1));
        stringstream sin(s1);
        map<string, int> m;

        while (sin >> a) {
            sin >> s2;
            s2 = s2.substr(0, s2.find(';'));
            s2 = s2.substr(0, s2.find(','));
            m[s2] = max(m[s2], a);
            // if ((s2 == "blue" && a > 14) || (s2 == "green" && a > 13) || (s2 == "red" && a > 12)) {
            //     ok = false;
            //     break;
            // }
        }
        answer += m["blue"] * m["green"] * m["red"];
    }

    cout << answer << '\n';

    submit(answer);

    return 0;
}