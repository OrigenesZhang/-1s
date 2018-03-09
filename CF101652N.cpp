#include<iostream>
using namespace std;

string s;

bool check(int i, int j) {
    while(i < j) {
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

int main() {
    bool ok = true;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        for(int j = i + 1; j < s.length(); j += 2)
            if(check(i, j)) ok = false;
    if(ok) cout << "Odd.\n";
    else cout << "Or not.\n";
    return 0;
}
