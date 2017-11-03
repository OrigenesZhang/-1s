#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#define maxn 100010
using namespace std;
int tot = 0;
int anspeople[maxn];
// int anshouse[maxn];
int vis[maxn];
int n, m;

struct peo {int id, num;} people[maxn];

struct hou {int id, num, fee;} house[maxn];

bool cmppeo(peo A, peo B) {return A.num < B.num;}
bool cmphou(hou A, hou B) {return A.fee < B.fee;}

int find_peo (int NUM) {
	int ret = 0;
	for (int i=1; i<=n; i++) {
		if (vis[i]) continue;
		if (people[i].num > NUM) break;
		ret = i;
	}
	return ret;
}


int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> people[i].num;
		people[i].id = i;
	}

	for (int i=1; i<=m; i++) {
		cin >> house[i].num;
		house[i].id = i;
	}
	for (int i=1; i<=m; i++) cin >> house[i].fee;
	sort(people+1, people+1+n, cmppeo);
	sort(house+1, house+1+m, cmphou);

	int cnt = 0;
	for (int i=1; i<=m; i++) {
		// printf("house %d : num %d\n", i, house[i].num);
		int tar = find_peo(house[i].num);
		if (tar == 0) continue;

		vis[tar] = 1;
		anspeople[people[tar].id] = house[i].id;
		++cnt;

		if (cnt == n) break;
	}
	if (cnt < n) {
		puts("impossible");
	}
	else {
		for (int i=1; i<=n; i++) {
			cout << anspeople[i] << " ";
		}
		puts("");
	}
	return 0;


}
/*



1 1
20
10
1

2 5
40 200
1000 199 201 10 50
600 300 400 200 800

3 5
10 20 30
30 25 20 15 10
30 25 20 15 10


*/
