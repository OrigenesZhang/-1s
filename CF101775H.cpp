#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

string s;
int t, limit[2], n, lis[1100100], cur[2];

bool check(int x) {
  int cnt = 0;
  FOR (i, 1, n) {
    if (lis[i] == 1 - x) cnt = 0;
    else cnt++;
    if (cnt >= limit[x]) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  FOR (cas, 1, t) {
    cout << "Case #" << cas << ": ";
    cin >> s >> limit[1] >> limit[0];
    n = s.size();
    REP (i, n) {
      if (s[i] == '?') lis[i + 1] = -1;
      else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') lis[i + 1] = 1;
      else lis[i + 1] = 0;
    }

    if (limit[0] == 1 || limit[1] == 1) {
      cout << "DISLIKE" << endl;
      continue;
    }

    bool canDislike = check(0) || check(1);
    bool canLike = true;

    reset(cur, 0);
    FOR (i, 1, n) {
      if (lis[i] == -1) {
        if (cur[0] == limit[0] - 1) cur[0] = 0, cur[1] = 1;
        else if (cur[1] == limit[1] - 1) cur[1] = 0, cur[0] = 1;
        else cur[0] = cur[1] = 0;
      } else {
        cur[lis[i]]++;
        cur[1 - lis[i]] = 0;
      }
      REP (j, 2) if (cur[j] >= limit[j]) canLike = false;
    }

    if (canDislike) {
      if (canLike) cout << "SURPRISE";
      else cout << "DISLIKE";
    } else {
      if (canLike) cout << "LIKE";
      else assert(0);
    }
    cout << endl;
  }
}