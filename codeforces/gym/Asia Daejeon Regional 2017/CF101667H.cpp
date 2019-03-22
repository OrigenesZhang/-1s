#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define uni(x) x.erase(unique(all(x)), x.end());
#define BUG(x) cout << #x << " = " << x << endl
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto _i:x) cout << _i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 1e-7
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

struct FFT {
  const static int nmax = 500100;
  complex<double> resA[nmax],resB[nmax];
  template<class T> void fft(T A[], complex<double> res[], int step, int n, int cs) {
    if (n == 1) {
      res[0] = A[0];
      return;
    }
    complex<double> w_n = polar(1.0, cs*2*pi/n), w = 1, tmp;
    n/=2;
    fft(A, res, step*2, n, cs);
    fft(A + step, res+n, step*2, n, cs);
    for(int i = 0; i < n; i++) {
      tmp = res[i+n] * w;
      res[i+n] = res[i] - tmp;
      res[i] += tmp;
      w *= w_n;
    }
  }
  // n is power of 2, number of coefficient of a and b
  void solve(int *a, int *b, int *res, int n) {
    n*=2;
    fft(a, resA, 1, n, 1);
    fft(b, resB, 1, n, 1);
    for(int i=0; i<n; i++) resA[i] *= resB[i];
    fft(resA, resB, 1, n , -1);
    for(int i=0; i < n; i++) res[i] = (int) (resB[i].real()/n + 0.5);
  }
};

int n, m, ans;
string s1, s2;
int a[1 << 19], b[1 << 19], c[1 << 19], res[1 << 19];
string s = "RPS";
FFT fft;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> s1 >> s2;
  REP (i, 3) {
    char c1 = s[i];
    char c2 = s[(i + 1) % 3];
    REP (j, n) if (s1[j] == c1) a[j] = 1; else a[j] = 0;
    REP (j, m) if (s2[j] == c2) b[m - 1 - j] = 1; else b[m - 1 - j] = 0;
    fft.solve(a, b, c, (1 << 17));
    REP (j, n + m + 5) res[j] += c[j];
  }
  FOR (j, m - 1, n + m + 5) ans = max(ans, res[j]);
  cout << ans;
}
