#include <bits/stdc++.h>

using namespace std;

const int maxn = 5123;

bool vis[maxn];
int sg[maxn], T, n;

int main() {
    sg[2] = sg[3] = 1;
    for (int i = 4; i <= 5000; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= i - 2; j++) vis[sg[j] ^ sg[i - j - 2]] = true;
        for (int j = 0; j <= 5000; j++) if (!vis[j]) {
            sg[i] = j;
            break;
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        puts(sg[n] ? "First" : "Second");
    }
}