#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char buffer[420];

const int DAY = 4;
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

    // download();

    ifstream fin(to_string(DAY) + "input.txt");
    int out = 0;

    cout << out << '\n';

    //   submit(out);
}