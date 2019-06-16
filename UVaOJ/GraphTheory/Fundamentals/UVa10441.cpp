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

int T, n, in[26], out[26], ptr[26];
vector<int> G[26];
vector<string> tab[26];
stack<string> s;

void dfs(int u) {
  while (out[u]) {
    out[u]--, in[G[u][ptr[u]]]--;
    int v = ptr[u];
    ptr[u]++;
    dfs(G[u][v]);
    s.emplace(tab[u][v]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  while (T--) {
    reset(in, 0);
    reset(out, 0);
    reset(ptr, 0);
    REP(i, 26) {
      G[i].clear();
      tab[i].clear();
    }
    cin >> n;
    string now;
    FOR(i, 1, n) {
      cin >> now;
      tab[now.front() - 'a'].eb(now);
      in[now.back() - 'a']++;
      out[now.front() - 'a']++;
    }
    int head = -1, tail = -1, cnt = 0;
    bool flag = true;
    REP(i, 26) {
      if (in[i] == out[i]) continue;
      if (in[i] == out[i] + 1) {
        if (tail == -1) tail = i, cnt++;
        else {
          flag = false;
          break;
        }
      } else if (in[i] + 1 == out[i]) {
        if (head == -1) head = i, cnt++;
        else {
          flag = false;
          break;
        }
      } else {
        flag = false;
        break;
      }
    }
    if (!flag || cnt == 1) {
      cout << "***\n";
      continue;
    }
    REP(i, 26) {
      sort(all(tab[i]));
      G[i].resize(tab[i].size());
      REP(j, int(tab[i].size())) G[i][j] = tab[i][j].back() - 'a';
    }
    if (head == -1) {
      REP(i, 26) if (out[i]) {
        head = i;
        break;
      }
    }
    dfs(head);
    REP(i, 26) if (in[i] || out[i]) {
      flag = false;
      break;
    }
    if (!flag) {
      while (!s.empty()) s.pop();
      cout << "***\n";
      continue;
    }
    while (!s.empty()) {
      if (!flag) cout << '.';
      flag = false;
      cout << s.top();
      s.pop();
    }
    cout << '\n';
  }
}
