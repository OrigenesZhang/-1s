#include <bits/stdc++.h>
using namespace std;

int v;

int main() {
	int ans = int(1e9);
	cin >> v;
	for (int i = 1; i <= 1000; i++) {
		if (v % i == 0) {
			for (int j = i; j <= 1000; j++) {
				if ((v / i) % j == 0) {
					int c = v / i / j;
					ans = min(ans, 2 * (i * j + i * c + j * c));
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}