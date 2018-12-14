#include <bits/stdc++.h>
using namespace std;

const int N = 112345;

int a[N], n, x;
int ans;

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] <= x / 2) ans = max(ans, i + 1);
		else {
			int pos = upper_bound(a, a + n, x - a[i]) - a;
			ans = max(ans, pos + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}