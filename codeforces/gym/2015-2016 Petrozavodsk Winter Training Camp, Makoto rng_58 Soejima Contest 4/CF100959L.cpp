#include <bits/stdc++.h>
using namespace std;

const int maxn = 5123;

char s[maxn], t[maxn];

int main() {
    scanf("%s%s", s, t);
    int l = 0, r = 0;
    while (s[l] && s[l] == s[0]) l++;
    while (t[r] && t[r] == t[0]) r++;
    if (s[0] != t[0] || l < r) {
        puts("No");
        return 0;
    }
    r = l;
    for (; s[l]; l++) {
        while (t[r] && t[r] != s[l]) r++;
        if (!t[r]) {
            puts("No");
            return 0;
        }
        r++;
    }
    puts("Yes");
}