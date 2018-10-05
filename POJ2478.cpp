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
ll phi[maxn];
bool vis[maxn];

void init() {
	FOR(i, 2, upp) {
		if (!vis[i]) {
			primes[pcnt++] = i;
			phi[i] = i - 1;
		}
		REP(j, pcnt) {
			if (ll(i) * primes[j] > upp) break;
			vis[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			} else {
				phi[i * primes[j]] = phi[i] * phi[primes[j]];
			}
		}
	}
	FOR(i, 2, upp) phi[i] = phi[i] + phi[i - 1];
}

int main() {
	init();
	int n;
	while (scanf("%d", &n) == 1 && n)
		printf("%lld\n", phi[n]);
	return 0;
}
