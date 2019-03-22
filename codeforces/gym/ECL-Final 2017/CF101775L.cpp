#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define reset(a, b) memset(a, b, sizeof(a))
typedef long long ll;
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	FOR(cs, 1, T) {
		scanf("%d", &n);
		printf("Case #%d: ", cs);
		if (n & 1) {
			puts(n >= 7 ? "Panda" : "Draw");
		} else {
			puts(n >= 16 ? "Sheep" : "Draw");
		}
	}
	return 0;
}