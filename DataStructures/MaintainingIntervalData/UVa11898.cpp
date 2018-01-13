//暴力出奇迹
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=201234;
const int maxa=10000;
int a[maxn], cnt[maxa+123], T, N, Q, l, r, p, res;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=0; i<N; i++) scanf("%d", &a[i]);
		scanf("%d", &Q);
		while(Q--){
			scanf("%d%d", &l, &r);
			if(r-l+1>maxa){
				puts("0");
				continue;
			}
			memset(cnt, 0, sizeof(cnt));
			for(int i=l-1; i<r; i++){
				if(cnt[a[i]]==1){
					puts("0");
					goto label;
				}
				cnt[a[i]]++;
			}
			p=-maxa, res=maxa;
			for(int i=1; i<=maxa; i++){
				if(cnt[i]){
					res=min(res, i-p);
					p=i;
				}
			}
			printf("%d\n", res);
			label:;
		}
	}
	return 0;
}
