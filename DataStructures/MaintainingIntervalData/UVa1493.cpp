//并查集orz
//线段树的做法应该是每行建一个树然后每条询问进行区间维护
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxm=50015;
const int maxn=205;
struct op{
	char shape;
	int xc, yc, l, r, c;
}ops[maxm];
int p[maxn][maxm], cnt[15], n, m, q;
void init(){
	char ins[15];
	for(int i=0; i<q; i++){
		scanf("%s", ins);
		ops[i].shape=ins[0];
		if(ins[0]=='R') scanf("%d%d%d%d%d", &ops[i].xc, &ops[i].yc, &ops[i].l, &ops[i].r, &ops[i].c);
		else scanf("%d%d%d%d", &ops[i].xc, &ops[i].yc, &ops[i].r, &ops[i].c);
	}
	for(int i=0; i<=m; i++) p[0][i]=i;
	for(int i=1; i<=n; i++) memcpy(p[i], p[0], sizeof(p[0]));
	memset(cnt, 0, sizeof(cnt));
}
int Find(int x, int y){
	return y==p[x][y]?y:p[x][y]=Find(x, p[x][y]);
}
void circle(int x, int y, int r, int c){
	int L, R, len;
	for(int i=-r; i<=r; i++){
		len=sqrt(r*r-i*i);
		if(i+x>=n||i+x<0) continue;
		L=max(y-len, 0);
		L=max(Find(i+x, L), L);
		R=min(len+y, m-1);
		for(int j=L; j<=R; j++){
			if(j==Find(i+x, j)){
				cnt[c]++;
				p[i+x][j]=R+1;
			}else j=Find(i+x, j)-1;
		}
	}
}
void diamond(int x, int y, int r, int c){
	int L, R;
	for(int i=-r; i<=r; i++){
		if(i+x>=n||i+x<0) continue;
		R=min(r-abs(i)+y, m-1);
		L=max(abs(i)-r+y, 0);
		L=max(L, Find(i+x, L));
		for(int j=L; j<=R; j++){
			if(j==Find(i+x, j)){
				cnt[c]++;
				p[i+x][j]=R+1;
			}else j=Find(i+x, j)-1;
		}
	}
}
void rectangle(int x, int y, int l, int w, int c){
	int L, R;
	for(int i=x; i<min(x+l, n); i++){
		L=max(y, Find(i, y));
		R=min(y+w-1, m-1);
		for(int j=L; j<=R; j++){
			if(j==Find(i, j)){
				cnt[c]++;
				p[i][j]=R+1;
			}else j=Find(i, j)-1;
		}
	}
}
void triangle(int x, int y, int w, int c){
	int L, R, h;
	h=w+1>>1;
	for(int i=0; i<h; i++){
		if(i+x>=n) break;
		L=max(y-h+i+1, 0);
		L=max(Find(i+x, L), L);
		R=min(y+h-i-1, m-1);
		for(int j=L; j<=R; j++){
			if(j==Find(i+x, j)){
				cnt[c]++;
				p[i+x][j]=R+1;
			}else j=Find(i+x, j)-1;
		}
	}
}
int main(){
	while(scanf("%d%d%d", &n, &m, &q)==3){
		init();
		while(q--){
			switch(ops[q].shape){
				case 'C':
					circle(ops[q].xc, ops[q].yc, ops[q].r, ops[q].c);
					break;
				case 'D':
					diamond(ops[q].xc, ops[q].yc, ops[q].r, ops[q].c);
					break;
				case 'R':
					rectangle(ops[q].xc, ops[q].yc, ops[q].l, ops[q].r, ops[q].c);
					break;
				default:
					triangle(ops[q].xc, ops[q].yc, ops[q].r, ops[q].c);
					break;
			}
		}
		for(int i=1; i<9; i++)
			printf("%d ", cnt[i]);
		printf("%d\n", cnt[9]);
	}
	return 0;
}
