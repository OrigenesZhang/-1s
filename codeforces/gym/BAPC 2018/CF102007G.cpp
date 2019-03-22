#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

const int maxn = 112345;
const int inf = 1e6;

int n, ans = inf;
char a[maxn * 2];
map<char, int> cnt;

int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	FOR(i, 1, n) {
		cnt[a[i]]++;
		a[i + n] = a[i];
	}
	char lis[] = {'A', 'B', 'C'};
	do {
		int now = 0;
		FOR(i, 1, cnt[lis[0]]) now += a[i] != lis[0];
		FOR(i, cnt[lis[0]] + 1, cnt[lis[0]] + cnt[lis[1]]) now += a[i] != lis[1];
		FOR(i, cnt[lis[0]] + cnt[lis[1]] + 1, n) now += a[i] != lis[2];
		ans = min(ans, now);
		FOR(st, 2, n) {
			if (a[st - 1] != lis[0]) now--;
			if (a[st + cnt[lis[0]] -1] != lis[1]) now--;
			if (a[st + cnt[lis[0]] + cnt[lis[1]] - 1] != lis[2]) now--;
			if (a[st + cnt[lis[0]] -1] != lis[0]) now++;
			if (a[st + cnt[lis[0]] + cnt[lis[1]] - 1] != lis[1]) now++;
			if (a[st + n - 1] != lis[2]) now++;
			ans = min(ans, now);
		}
	} while (next_permutation(lis, lis + 3));
	printf("%d\n", ans);
}