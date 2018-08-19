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

int n, cnt;
string s[555], ss, line;
map<string, int> id;
vector<int> adj[555], ans;
int bfs[555], pre[555];
queue<int> q;

void trace(int cur, int x) {
  ans.clear();
  while (cur != x) ans.pb(cur), cur = pre[cur];
  ans.pb(x);
}

void solve(int x) {
  reset(bfs, -1);
  bfs[x] = 0;
  q.push(x);
  
  while (q.size()) {
    int cur = q.front();
    q.pop();
    for (auto nex: adj[cur]) {
      if (nex == x && (bfs[cur] + 1 < ans.size() || ans.empty())) trace(cur, x);
      else if (bfs[nex] == -1) bfs[nex] = bfs[cur] + 1, q.push(nex), pre[nex] = cur;
    }
  }
}

int main() {
  cin >> n;
  REP (i, n) cin >> s[i], id[s[i]] = i;
  REP (i, n) {
    cin >> ss >> cnt;
    int cur = id[ss];
    while (cnt--) {
      line = "";
      while (line == "") getline(cin, line);
      stringstream sss(line);
      sss >> ss;
      while (sss >> ss) {
        if (ss[ss.size() - 1] == ',') ss = ss.substr(0, ss.size() - 1);
        adj[cur].pb(id[ss]);
      }
    }
  }

  REP (i, n) solve(i);
  reverse(all(ans));
  if (ans.size()) for (auto i: ans) cout << s[i] << ' ';
  else cout << "SHIP IT";
}