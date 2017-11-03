//2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
#include <bits/stdc++.h>
using namespace std;
const int maxn=1825*100+500;
int N, H, R, T, mmax;
bool table[20][maxn];
int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>H>>R>>T;
		if(H*1825>mmax) mmax=H*1825;
		if(T-R==1) continue;
		T--;
		if(T==-1) T=H-1;
		R++;
		if(R==H) R=0;
		if(R>T){
			for(int j=0; j<=T; j++) table[i][j]=true;
			T+=H;
		}
		while(R<maxn-480){
			for(int j=R; j<=T; j++)
				table[i][j]=true;
			R+=H;
			T+=H;
		}
	}
	for(int i=0; i<mmax; i++){
		bool flag=false;
		for(int j=0; j<N; j++)
			if(table[j][i]){
				flag=true;
				break;
			}
		if(!flag){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"impossible"<<endl;
	return 0;
}
