#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int n;
bool have[N];
char name[N];

const int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int convert(int month, int day) {
	int ans = day;
	for (int i = 1; i < month; i++) ans += a[i];
	return ans;
}

pair<int, int> convert2(int num) {
	int sum = 0, month = -1, day = -1;
	for (int i = 1; i <= 12; i++) {
		if (sum + a[i] >= num) {
			month = i;
			day = num - sum;
			break;
		} else sum += a[i];
	}
	return make_pair(month, day);
}

int judge(int val) {
	int a = val - convert(10, 27);
	if (a <= 0) a += 365;
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int month, day;
		scanf("%d-%d", &month, &day);
		have[convert(month, day)] = true;
		//cout << convert(month, day) << endl;
	}

	int last = 0;

	for (int i = 1; i <= 365; i++) {
		if (have[i]) last = i - 365;
	}

	//cout << last << endl;
	//cout << convert(4, 28) - last << ' ' << convert(10, 28) - convert(4, 30) << endl;


	int ans = 5000, maxm = 0;
	for (int i = 1; i <= 365; i++) {
		if (have[i]) {
			last = i;
		} else {
			if (i - last > maxm || (i - last == maxm && judge(i) < judge(ans))) {
				maxm = i - last;
				ans = i;
			}
		}
	}

	//cout << convert(10, 28) << endl;
	//cout << convert(4, 29) << endl;

	//cout << maxm << ' ' << ans << '\n';

	pair<int, int> date = convert2(ans);
	printf("%02d-%02d\n", date.first, date.second);
	return 0;
}