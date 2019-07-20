#include <bits/stdc++.h>
using namespace std;
 
vector<string> process(string cur) {
  vector<string> ans;
  int nxt = 0;
  for (int i = 0; i < int(cur.length()); ) {
    if (isalpha(cur[i])) {
      string t;
      t.push_back(cur[i]);
      ans.push_back(t);
      i++;
    } else {
      nxt = i;
      string tmp;
      while (nxt < cur.length() && isdigit(cur[nxt])) tmp.push_back(cur[nxt++]);
      i = nxt;
      ans.push_back(tmp);
    }
  }
  return ans;
}
 
int trans(string cur) {
  int ans = 0;
  for (int i = 0; i < cur.length(); i++) {
    ans = ans * 10 + cur[i] - '0';
  }
  return ans;
}
 
bool compare(vector<string> b, vector<string> cur) {
  for (int i = 0; i < min(b.size(), cur.size()); i++) {
    if (isdigit(b[i][0])) {
      if (isalpha(cur[i][0])) return true;
      else {
        int fir = trans(b[i]), sec = trans(cur[i]);
        if (fir < sec) return true;
        if (fir > sec) return false;
      }
    } else {
      if (isdigit(cur[i][0])) return false;
      else {
        if (b[i] < cur[i]) return true;
        if (b[i] > cur[i]) return false;
      }
    }
  }
 
  if (b.size() > cur.size()) return false;
  else return true;
}
 
string base, s;
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n;
  cin >> n >> base;
 
  vector<string> b = process(base);
 
  for (int i = 0; i < n; i++) {
    cin >> s;
    vector<string> tmp = process(s);
    if (compare(b, tmp)) cout << "+" << endl;
    else cout << "-" << endl;
  }
 
  return 0;
}
 
/*
 11
 X52Y
 X
 X5
 X52
 X52Y
 X52Y6
 32
 ABC
 XYZ
 x51y
 X8Y
 X222
 */