#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 112345;

LL p[N], c[N];
int n, m;

bool judge(int day) {
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] * day > c[i]) sum += p[i] * day - c[i];
		if (sum >= m) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i] >> c[i];

	int l = 1, r = int(2e9);
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}