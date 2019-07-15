#include <bits/stdc++.h>
using namespace std;
#define pb push_back
 
int n;
string s;
 
string deal() {
  string ret = s;
 
  char a = s[s.length() - 2], b = s[s.length() - 1];
 
  if (b == 'a' || b == 'o' || b == 'u') ret.pb('s');
  else if (b == 'i') ret += "os";
  else if (b == 'y') { ret.pop_back(); ret += "ios"; }
  else if (b == 'l' || b == 'r' || b == 'v') { ret += "es"; }
  else if (b == 'n') { ret.pop_back(); ret += "anes"; }
  else if (a == 'n' && b == 'e') { ret.pop_back(); ret.pop_back(); ret += "anes"; }
  else if (b == 't' || b == 'w') ret += "as";
  else ret += "us";
 
  return ret;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n;
 
  while (n--) {
    cin >> s;
    cout << deal() << '\n';
  }
 
  return 0;
}