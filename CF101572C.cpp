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

int n, r[100500], g[100500], b[100500], id[100500];
map<int, int> m;
set<int> rcon[360], gcon[360], bcon[360];
set<pair<int, pair<int, int>>> s;

void updateScore(int x, int offset) {
  int oldScore = m[x];
  int newScore = m[x] + offset;
  s.erase({oldScore, {-id[x], x}});
  s.insert({newScore, {-id[x], x}});
  m[x] = newScore;
}

int findRR (int i) {
  FOR (j, 1, 359) if (rcon[(r[i] + j) % 360].size()) {
    return j;
  }
  return 0;
}

int findRL (int i) {
  FOR (j, 1, 359) if (rcon[(r[i] - j + 360) % 360].size()) {
    return j;
  }
  return 0;
}

int findGR (int i) {
  FOR (j, 1, 359) if (gcon[(g[i] + j) % 360].size()) {
    return j;
  }
  return 0;
}

int findGL (int i) {
  FOR (j, 1, 359) if (gcon[(g[i] - j + 360) % 360].size()) {
    return j;
  }
  return 0;
}

int findBR (int i) {
  FOR (j, 1, 359) if (bcon[(b[i] + j) % 360].size()) {
    return j;
  }
  return 0;
}

int findBL (int i) {
  FOR (j, 1, 359) if (bcon[(b[i] - j + 360) % 360].size()) {
    return j;
  }
  return 0;
}


void update(int x) {
  rcon[r[x]].erase(x);
  gcon[g[x]].erase(x);
  bcon[b[x]].erase(x);

  REP (i, 360) if (rcon[(r[x] + i) % 360].size()) {
    if (rcon[(r[x] + i) % 360].size() > 1) break;
    int cur = *(rcon[(r[x] + i) % 360].begin());
    updateScore(cur, findRL(cur) - i);
    break;
  }

  REP (i, 360) if (rcon[(r[x] - i + 360) % 360].size()) {
    if (rcon[(r[x] - i + 360) % 360].size() > 1) break;
    int cur = *(rcon[(r[x] - i + 360) % 360].begin());
    updateScore(cur, findRR(cur) - i);
    break;
  }

  REP (i, 360) if (gcon[(g[x] + i) % 360].size()) {
    if (gcon[(g[x] + i) % 360].size() > 1) break;
    int cur = *(gcon[(g[x] + i) % 360].begin());
    updateScore(cur, findGL(cur) - i);
    break;
  }

  REP (i, 360) if (gcon[(g[x] - i + 360) % 360].size()) {
    if (gcon[(g[x] - i + 360) % 360].size() > 1) break;
    int cur = *(gcon[(g[x] - i + 360) % 360].begin());
    updateScore(cur, findGR(cur) - i);
    break;
  }

  REP (i, 360) if (bcon[(b[x] + i) % 360].size()) {
    if (bcon[(b[x] + i) % 360].size() > 1) break;
    int cur = *(bcon[(b[x] + i) % 360].begin());
    updateScore(cur, findBL(cur) - i);
    break;
  }

  REP (i, 360) if (bcon[(b[x] - i + 360) % 360].size()) {
    if (bcon[(b[x] - i + 360) % 360].size() > 1) break;
    int cur = *(bcon[(b[x] - i + 360) % 360].begin());
    updateScore(cur, findBR(cur) - i);
    break;
  }
}

int main() {
  cin >> n;
  REP (i, n) cin >> r[i] >> g[i] >> b[i] >> id[i], rcon[r[i]].insert(i), gcon[g[i]].insert(i), bcon[b[i]].insert(i);
  if (n == 1) {
    cout << id[0];
    return 0;
  }

  REP (i, n) {
    int score = 0;
    if (rcon[r[i]].size() == 1) {
      score += findRL(i) + findRR(i);
    }
    if (gcon[g[i]].size() == 1) {
      score += findGL(i) + findGR(i);
    }
    if (bcon[b[i]].size() == 1) {
      score += findBL(i) + findBR(i);
    }
    m[i] = score;
    s.insert({score, {-id[i], i}});
  }

  while (s.size()) {
    auto it = s.begin();
    cout << -it->_2._1 << endl;

    update(it->_2._2);
    s.erase(it);
    //for (auto i: s) BUG(i._1), BUGP(i._2);
  }
}