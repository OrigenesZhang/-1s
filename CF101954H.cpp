#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define sqr(x) ((x) * (x))
#define pb push_back
#define _1 first
#define _2 second

int n, val, gr[2222], vst[2222], ans;

int main() {
  ios::sync_with_stdio(0);
  FOR (i, 2, 2000) {
    reset(vst, 0);
    FOR (j, 1, i - 1) {
      int tmp = i / j;
      int cur = gr[i % j];
      if (tmp & 1) cur ^= gr[j];
      vst[cur] = 1;
    }
    int cur = 0;
    while (vst[cur]) cur++;
    gr[i] = cur;
  }

  cin >> n;
  while (n--) {
    cin >> val;
    ans ^= gr[val];
  }
  if (ans) cout << "First";
  else cout << "Second";
}