#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl
#define pb push_back

long long k, n, l[500500], r[500500], st[500500], deg[500500], pending[500500], ans[500500];
queue<int> q;
char c;

int main() {
  cin >> k >> n;
  FOR (i, 1, n) {
    cin >> c >> l[i] >> r[i];
    st[i] = (c == 'L') ? 0 : 1;
    deg[l[i]]++;
    deg[r[i]]++;
  }
  FOR (i, 1, n) if (!deg[i]) q.push(i);
  pending[1] = k;

  while (q.size()) {
    int cur = q.front(); q.pop();
    if (l[cur]) {
      int nex = l[cur];
      pending[nex] += pending[cur] / 2;
      if (!st[cur]) pending[nex] += pending[cur] % 2;
      deg[nex]--;
      if (!deg[nex]) q.push(nex);
    }
    if (r[cur]) {
      int nex = r[cur];
      pending[nex] += pending[cur] / 2;
      if (st[cur]) pending[nex] += pending[cur] % 2;
      deg[nex]--;
      if (!deg[nex]) q.push(nex);
    }
    ans[cur] = (st[cur] + pending[cur]) % 2;
  }
  FOR (i, 1, n) cout << ((ans[i] % 2) ? 'R' : 'L');
}