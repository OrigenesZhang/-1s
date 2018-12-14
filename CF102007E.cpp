#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;

const int maxn = 5123;
const ll MOD = 1e9 + 9;

int n, a[maxn];
ll p[maxn], dp[maxn], in[maxn];
unordered_map<int, int> cnt[maxn];

ll inv(ll a) {
	ll ret = 1, pw = MOD - 2;
	while (pw) {
		if (pw & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
  FOR(i, 1, 5000) in[i] = inv(i);
	dp[0] = 1;
	p[0] = 1;
	FOR(i, 1, n) {
    ROF(j, i, 1) cnt[j][a[i]]++;
		ROF(j, i, 1) p[j] = p[j - 1] * j % MOD * in[cnt[i - j + 1][a[i]]] % MOD;
    FOR(j, 1, i) dp[i] = (dp[i] - dp[j - 1] * p[i - j]) % MOD;
		dp[i] = ((dp[i] + p[i]) % MOD + MOD) % MOD;
  }
	printf("%lld\n", dp[n]);
}
