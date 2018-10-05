#include <cstdio>
#include <cstring>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;
typedef long long ll;

const int maxn = 1234567;
const int upp = 1e6;

int primes[maxn], pcnt;
bool vis[maxn];

void init() {
	primes[pcnt++] = 2;
	for (int i = 3; i <= upp; i += 2) {
		if (!vis[i]) primes[pcnt++] = i;
		REP(j, pcnt) {
			if (ll(i) * primes[j] > upp) break;
			vis[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

char s[123];
int L, ss[123];

bool judge(int p, int n) {
	int rem = 0;
	ROF(i, n - 1, 0)
		rem = (rem * 1000 + ss[i]) % p;
	return rem == 0;
}

int main() {
	init();
	while (scanf("%s%d", s, &L) == 2) {
		if (s[0] == '0') break;
		int n = strlen(s), now = n - 1, cur = 0;
		while (now >= 0) {
			ss[cur] = s[now] - '0';
			if (now > 0) ss[cur] += (s[now - 1] - '0') * 10;
			if (now > 1) ss[cur] += (s[now - 2] - '0') * 100;
			now -= 3;
			cur++;
		}
		REP(i, pcnt) {
			if (primes[i] >= L) break;
			if (judge(primes[i], cur)) {
				printf("BAD %d\n", primes[i]);
				goto label;
			}
		}
		puts("GOOD");
		label:;
	}
	return 0;
}
