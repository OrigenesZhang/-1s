#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define _1 first
#define _2 second
typedef pair<int, int> pii;

const int maxn = 212345;
const int maxc = 112345;

int en[maxc], ex[maxc], ans[2], mark[maxc];
pii p[maxn];
int n;

inline int lowbit(int x) {
	return x & (-x);
}

void update(int * arr, int x, int d) {
	while (x < maxc) {
		arr[x] += d;
		x += lowbit(x);
	}
}

int query(const int * arr, int x) {
	int ret = 0;
	while (x > 0) {
		ret += arr[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d%d", &p[i]._1, &p[i]._2);
		// ans[0] = max(ans[0], query(en, p[i]._2 - 1) - query(ex, p[i]._1) + 1);
		// ans[0] = max(ans[0], en[p[i]._2 - 1] - ex[p[i]._1] + 1);
		// update(en, p[i]._1, 1);
		// update(ex, p[i]._2, 1);
		// en[p[i]._1]++, ex[p[i]._2 - 1]++;
		en[p[i]._1]++, ex[p[i]._2]++;
		mark[p[i]._1]++, mark[p[i]._2]--;
	}
	FOR(i, 0, maxc - 1) {
		if (i) {
			mark[i] += mark[i - 1];
			en[i] += en[i - 1];
			ex[i] += ex[i - 1];
		}
		ans[1] = max(ans[1], mark[i]);
	}
	FOR(i, 1, n)
		ans[0] = max(ans[0], en[p[i]._2 - 1] - ex[p[i]._1]);
	printf("%d %d\n", ans[0], ans[1]);
}