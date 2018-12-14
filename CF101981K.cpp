#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define pb push_back
using namespace std;

const int N = 20 + 5;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const char dir[] = "DLUR";
string s[N];

struct Node {
    int r, c;
    bool operator < (const Node& rhs) const {
        return r < rhs.r || (r == rhs.r && c < rhs.c);
    }
};

int n, m;
vector<Node> node;
string ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(NULL));
    for (int i = 0; i < 50000; i++) {
        int cur = rand() % 4;
        ans.pb(dir[cur]);
    }

    cout << ans << '\n';
    return 0;
}