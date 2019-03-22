#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-8
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
using namespace std;

int n, m, vst[1 << 20], cur;
string s;
queue<int> q;

int get() {
  cin >> s;
  int ret = 0;
  REP (i, m) ret += (1 << i) * (s[i] - '0');
  return ret;
}

int main() {
  cin >> n >> m;
  while (n--) {
    cur = get();
    vst[cur] = 1;
    q.push(cur);
  }

  while (q.size()) {
    cur = q.front();
    q.pop();
    REP (i, m) {
      int nex = cur ^ (1 << i);
      if (!vst[nex]) q.push(nex), vst[nex] = 1;
    }
  }

  REP (i, m) if (cur & (1 << i)) cout << 1; else cout << 0;
}