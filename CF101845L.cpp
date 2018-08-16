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

const int N = 2048 + 10;

int n, locr, locc, f[N][N], t, vst[N][N];
char ans[N][N];

void solve(int r1, int r2, int c1, int c2, int posr, int posc) {
  if (r1 == r2) return;
  int midr = (r1 + r2) / 2, midc = (c1 + c2) / 2;
  // judge
  if (posr <= midr && posc <= midc) {
    f[midr][midc + 1] = f[midr + 1][midc + 1] = f[midr + 1][midc] = ++t;
    solve(r1, midr, c1, midc, posr, posc);
    solve(r1, midr, midc + 1, c2, midr, midc + 1);
    solve(midr + 1, r2, c1, midc, midr + 1, midc);
    solve(midr + 1, r2, midc + 1, c2, midr + 1, midc + 1);
  } else if (posr <= midr && posc > midc) {
    f[midr][midc] = f[midr + 1][midc] = f[midr + 1][midc + 1] = ++t;
    solve(r1, midr, c1, midc, midr, midc);
    solve(r1, midr, midc + 1, c2, posr, posc);
    solve(midr + 1, r2, c1, midc, midr + 1, midc);
    solve(midr + 1, r2, midc + 1, c2, midr + 1, midc + 1);
  } else if (posr > midr && posc <= midc) {
    f[midr][midc] = f[midr][midc + 1] = f[midr + 1][midc + 1] = ++t;
    solve(r1, midr, c1, midc, midr, midc);
    solve(r1, midr, midc + 1, c2, midr, midc + 1);
    solve(midr + 1, r2, c1, midc, posr, posc);
    solve(midr + 1, r2, midc + 1, c2, midr + 1, midc + 1);
  } else {
    f[midr][midc] = f[midr][midc + 1] = f[midr + 1][midc] = ++t;
    solve(r1, midr, c1, midc, midr, midc);
    solve(r1, midr, midc + 1, c2, midr, midc + 1);
    solve(midr + 1, r2, c1, midc, midr + 1, midc);
    solve(midr + 1, r2, midc + 1, c2, posr, posc);
  }
}

char cur;
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
vector<pair<int, int>> v;
vector<char> vc;

void dfs(int r, int c) {
  vst[r][c] = 1;
  v.pb({r, c});
  REP (dd, 4) {
    int nr = r + dr[dd];
    int nc = c + dc[dd];
    if (nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
    vc.pb(ans[nr][nc]);
    if (!vst[nr][nc] && f[nr][nc] == f[r][c]) dfs(nr, nc);
  }
}


void print() {
  ans[locr][locc] = '.';
  FOR (i, 1, n) FOR (j, 1, n) if (!vst[i][j] && ans[i][j] != '.') {
    cur = 'A';
    dfs(i, j);
    sort(all(vc));
    for (auto cc: vc) if (cc == cur) cur++;
    vc.clear();
    for (auto p: v) ans[p._1][p._2] = cur;
    v.clear();
  }
  FOR (i, 1, n) {
    FOR (j, 1, n) cout << ans[i][j];
    cout << endl;
  }
}

int main() {
  cin >> n >> locr >> locc;
  solve(1, n, 1, n, locr, locc);
  print();
  //    for (int i = 1; i <= n; i++) {
  //        for (int j = 1; j <= n; j++) cout << f[i][j] << '\t';
  //        cout << endl;
  //    }
  return 0;
}