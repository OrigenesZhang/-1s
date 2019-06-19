#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;
const int maxq = 1123456;

int T, n, q, clk;
int ch[maxn], in[maxn], out[maxn];
pii control[maxn], query[maxq];
vector<int> G[maxn];

void dfs(int u) {
  in[u] = ++clk;
  for (auto v : G[u]) dfs(v);
  out[u] = clk;
}

int main() {
  scanf("%d", &T);
  FOR(cs, 1, T) {
    scanf("%d", &n);
    REP(i, n) scanf("%d", ch + i);
    scanf("%d", &q);
    map<int, int> belong;
    vector<int> needs, pars;
    FOR(i, 1, q) {
      scanf("%d%d", &query[i]._1, &query[i]._2);
      if (query[i]._2 >= n) needs.eb(query[i]._2);
    }
    sort(all(needs));
    REP(i, n) G[i].clear();
    int j = 1;
    REP(i, n) {
      chkmax(j, i + 1);
      int en = j + ch[i] - 1;
      FOR(k, j, min(en, n - 1)) G[i].eb(k);
      if (en >= n && en >= j) {
        control[i] = {max(j, n), en};
        pars.eb(i);
      }
      j += ch[i];
    }
    j = 0;
    for (auto it : needs) {
      while (control[pars[j]]._2 < it) j++;
      belong[it] = pars[j];
    }
    clk = 0;
    dfs(0);
    printf("Case %d:\n", cs);
    FOR(i, 1, q) {
      int &u = query[i]._1, &v = query[i]._2;
      if (u == v || u >= n) {
        puts("No");
        continue;
      }
      if (v >= n) v = belong[v];
      puts(in[u] <= in[v] && out[v] <= out[u] ? "Yes" : "No");
    }
    if (cs != T) putchar('\n');
  }
}
/*
2
6
3 2 1 1 0 2
5
0 1
2 4
3 5
1 8
6 9
5
2 0 3 0 1
4
2 6
1 6
2 3
3 5
 */