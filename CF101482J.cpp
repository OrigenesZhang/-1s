#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> m[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[0][s]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[1][s]++;
	}
	int ans = 0;
	for (const auto &it : m[0])
		ans += min(m[1][it.first], it.second);
	cout << ans;
}