#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define BUG(x) cout << #x << " = " << x << endl;
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define pb push_back
#define _1 first
#define _2 second

long long n, val, size[100500], display[100500], expand[100500], cnt, t;
string s, name[100500], cur;
map<string, long long> m;
set<long long> child[100500];
vector<pair<string, pair<char, long long>>> ans;

long long id(string ss) {
  if (!m.count(ss)) {
    name[cnt] = ss;
    m[ss] = cnt++;
  }
  return m[ss];
}

void dfs(int x) {
  for (auto i: child[x]) {
    dfs(i);
    if (display[i]) expand[x] = 1;
  }
  if (expand[x]) for (auto i: child[x]) display[i] = 1;
  if (size[x] >= t) display[x] = 1;
}

void dfs2(int x) {
  for (auto i: child[x]) dfs2(i);
  if (display[x] || expand[x]) {
    char c = ' ';
    if (child[x].size()) {
      if (expand[x]) c = '-';
      else c = '+';
    }
    ans.pb({name[x], {c, size[x]}});
  }
}

int main() {
  cin >> n;
  id("/");
  REP (i, n) {
    cin >> s >> val;
    cur = "";
    long long par = -1;
    for (char c: s) {
      cur += c;
      if (c == '/') {
        long long id2 = id(cur);
        if (par != -1) {
          child[par].insert(id2);
          size[par] += val;
        }
        par = id2;
      }
    }
    size[par] += val;
  }
  cin >> t;
  dfs(id("/"));
  display[id("/")] = 1;
  dfs2(id("/"));
  sort(ans.begin(), ans.end());
  for (auto p: ans) cout << p._2._1 << ' ' << p._1 << ' ' << p._2._2 << endl;
}