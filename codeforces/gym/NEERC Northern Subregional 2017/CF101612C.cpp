#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ' ' << x._2 << endl
#define reset(a,b) memset(a,b,sizeof(a))
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for(auto _i: x) cout << _i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end())
#define mod 1000000007
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define pi acos(-1)
#define pb push_back
#define _1 first
#define _2 second

string s;
int edge[22][22], cnt, n, lis[1100100], bestmask, best, changed[22];
map<char, int> m;
vector<int> l, r;

bool isVowel(char c) {
  for (auto cc: "aeiouyw") if (c == cc) return true;
  return false;
}

int main() {
  freopen("consonant.in", "r", stdin);
  freopen("consonant.out", "w", stdout);
  cin >> s;
  n = s.size();
  REP (i, n) if (!isVowel(s[i])) {
    m[s[i]] = m[s[i]] ? m[s[i]] : ++cnt;
    lis[i] = m[s[i]];
  }

  REP (i, n - 1) if (lis[i] && lis[i + 1]) edge[lis[i] - 1][lis[i + 1] - 1]++, edge[lis[i + 1] - 1][lis[i] - 1]++;

  REP (mask, (1 << cnt)) {
    l.clear();
    r.clear();
    REP (i, cnt) if ((1 << i) & mask) l.pb(i); else r.pb(i);
    int cur = 0;
    for (auto i: l) for (auto j: r) cur += edge[i][j];
    if (cur > best) best = cur, bestmask = mask;
  }
  REP (i, cnt) if ((1 << i) & bestmask) changed[i + 1] = 1;
  REP (i, n) if (changed[m[s[i]]]) s[i] = s[i] - 'a' + 'A';
  cout << s;
}