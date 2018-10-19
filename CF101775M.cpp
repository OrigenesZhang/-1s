#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define reset(a, b) memset(a, b, sizeof(a))
typedef long long ll;
using namespace std;

const int maxn = 70;

ll p[maxn], cnt[maxn];
int T, n;

int main() {
	scanf("%d", &T);
	FOR(cs, 1, T) {
		ll now;
		scanf("%lld", &now);
		FOR(i, 1, 48) p[i] = now;
		scanf("%lld", &now);
		FOR(i, 49, 56) p[i] = now;
		scanf("%lld", &now);
		FOR(i, 57, 60) p[i] = now;
		scanf("%lld", &now);
		FOR(i, 61, 62) p[i] = now;
		scanf("%lld", &p[63]);
		reset(cnt, 0);
		scanf("%d", &n);
		while (n--) {
			scanf("%lld", &now);
			cnt[now]++;
		}
		ll tot = 0;
		FOR(i, 1, 63) tot += p[i] * cnt[i];
		tot *= 10000;
		printf("Case #%d: %lld\n", cs, tot);
	}
	return 0;
}