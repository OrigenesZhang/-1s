#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char tar[100010];
char tmp[100010];

int main() {
	scanf("%s", tar);
	int n = strlen(tar);
	for (int i=0; i<=n; i++) tmp[i] = tar[i];
	sort(tmp, tmp + n);

	for (int i=0; i<n; i++) {
		if (tmp[i] == tar[i]) continue;
		int j = i+1;
		for (; j<n; j++) {
			if (tmp[j] == tar[i]){
				break;
			}
		}
		if (tmp[j] > tmp[i])
			cout << j+1 << " " << i+1 << endl;
		else
			cout << i+1 << " " << j+1 << endl;
		swap(tmp[i], tmp[j]);
	}
	return 0;

}
