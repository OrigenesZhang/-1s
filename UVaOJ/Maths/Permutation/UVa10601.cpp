#include <iostream>
#include <cstring>
using namespace std;
const int maxn=12;
int cube[maxn+5], rod[maxn+5], T;
long long C[maxn+5][maxn+5];
void init(){
	C[0][0]=1;
	for(int i=1; i<=maxn; i++){
		C[i][0]=C[i][i]=1;
		for(int j=1; j<i; j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
long long cnt(int k){
	int n=0;
	long long res=1;
	for(int i=0; i<6; i++){
		if(cube[i]%k) return 0;
		cube[i]/=k;
		n+=cube[i];
	}
	for(int i=0; i<6; i++){
		res*=C[n][cube[i]];
		n-=cube[i];
	}
	return res;
}
long long still(){
	memcpy(cube, rod, sizeof(rod));
	return cnt(1);
}
long long r1(){
	memcpy(cube, rod, sizeof(rod));
	return 8*cnt(3);
}
long long r2(){
	long long res=0;
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			if(rod[i]&&rod[j]){
				memcpy(cube, rod, sizeof(rod));
				cube[i]--;
				cube[j]--;
				res+=6*cnt(2);
			}
		}
	}
	return res;
}
long long r3(){
	memcpy(cube, rod, sizeof(rod));
	long long res=6*cnt(4);
	memcpy(cube, rod, sizeof(rod));
	return res+3*cnt(2);
}
int main(){
	init();
	cin>>T;
	while(T--){
		int tmp;
		memset(rod, 0, sizeof(rod));
		for(int i=0; i<maxn; i++){
			cin>>tmp;
			rod[tmp-1]++;
		}
		cout<<(still()+r1()+r2()+r3())/24<<endl;
	}
	return 0;
}
