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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

pii lis[5];

int main() {
  int s = 0;
  REP(i, 3) {
    scanf("%d%d", &lis[i]._1, &lis[i]._2);
    if (lis[i]._1 < lis[i]._2) swap(lis[i]._1, lis[i]._2);
    s += lis[i]._1 * lis[i]._2;
  }
  int a = sqrt(s) + 0.5;
  if (a * a != s) {
    puts("NO");
    return 0;
  }
  sort(lis, lis + 3, greater<pii>());
  bool ok = false;
  if (lis[0]._1 == a) {
    int b = a - lis[0]._2;
    if (lis[1]._1 == lis[2]._1 && lis[1]._1 == a && lis[1]._2 + lis[2]._2 == b) ok = true;
    else if (lis[1]._1 == lis[2]._1 && lis[1]._1 == b && lis[1]._2 + lis[2]._2 == a) ok = true;
    else if (lis[1]._2 == lis[2]._2 && lis[1]._2 == b && lis[1]._1 + lis[2]._1 == a) ok = true;
    else if (lis[1]._2 == lis[2]._1 && lis[1]._2 == b && lis[1]._1 + lis[2]._2 == a) ok = true;
  }
  puts(ok ? "YES" : "NO");
}