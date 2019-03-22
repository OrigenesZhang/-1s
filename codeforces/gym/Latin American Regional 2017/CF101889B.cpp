#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool judge(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string s;

vector<int> vowel;
vector<int> cons;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (judge(s[i])) vowel.pb(i);
        else cons.pb(i);
    }

    if (vowel.size() == s.length() || vowel.empty()) cout << 1 << '\n';
    else if (!vowel.empty() && cons[0] == 0) cout << 0 << '\n';
    else if (vowel.size() == 1) cout << s.length() << '\n';
    else {
        int l = (vowel.size() - 1) / 2;
        int r = l + 1;
        cout << vowel[r] - vowel[l] << '\n';
    }
    return 0;
}