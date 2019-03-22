#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n;
unordered_set<int> s;

int f(int x) {
  int res = 0;
  while (x) {
    res += (x % 10) * (x % 10);
    x /= 10;
  }
  return res;
}

int main() {
  cin >> n;
  while (1) {
    if (n == 1) {
      cout << "HAPPY";
      return 0;
    }
    if (s.count(n)) {
      cout << "UNHAPPY";
      return 0;
    }
    s.insert(n);
    n = f(n);
  }
}
