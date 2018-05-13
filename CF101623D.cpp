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

int n, m;
string word, eng, judge;
vector<string> sentence, tran, itran;
map<string, vector<string> > cor, icor;
long long ans, ians;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  REP (i, n) cin >> word, sentence.pb(word);
  cin >> m;
  REP (i, m) {
    cin >> word >> eng >> judge;
    if (judge == "correct") cor[word].pb(eng);
    else icor[word].pb(eng);
  }
  ans = ians = 1;
  for (auto s: sentence) {
    int tmp1 = 0, tmp2 = 0;
    if (cor.count(s)) {
      tran.pb(cor[s][0]);
      ans *= cor[s].size();
      tmp1 = cor[s].size();
    } else ans = 0;
    if (icor.count(s)) {
      tmp2 = icor[s].size();
    }
    ians *= tmp1 + tmp2;
    if (tmp2) itran.pb(icor[s][0]);
    else if (tmp1) itran.pb(cor[s][0]);
  }
  if (ans == 1 && ians == 1) {
    for (auto s: tran) cout << s << ' ';
    cout << "correct";
  } else if (!ans && ians == 1) {
    for (auto s: itran) cout << s << ' ';
    cout << "incorrect";
  } else {
    cout << ans << " correct" << endl << ians - ans << " incorrect";
  }
}
