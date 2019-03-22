#include <bits/stdc++.h>

using namespace std;

int main() {
	double s1, s2, s3, s4, cs, si;
	cin >> s1 >> s2 >> s3 >> s4;
	cs = (s1 * s1 + s2 * s2 - s3 * s3 - s4 * s4) / (2 * s1 * s2 + 2 * s3 * s4);
	si = sqrt(1 - cs * cs);
	printf("%.15lf\n", (s1 * s2 * si + s3 * s4 * si) / 2);
}