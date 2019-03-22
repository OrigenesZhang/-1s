#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1000000;
int phi[maxn+50], cs=1, N;
double g[maxn+50], l, s[maxn+50];//s数组可以加快运算并且避免玄学精度问题
void phi_table(){
	phi[1]=1;
	for(int i=2; i<=maxn; i++){
		if(!phi[i]){
			for(int j=i; j<=maxn; j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
void init(){
	phi_table();
	for(int i=1; i<=maxn; i++){
		double tmp=log10(i);
		for(int j=2*i; j<=maxn; j+=i)
			g[j]+=phi[j/i]*tmp;
	}
	for(int i=1; i<=maxn; i++){
		g[i]+=g[i-1];
		s[i]=s[i-1]+log10(i);
	}
}
int main(){
	init();
	while(cin>>N){
		if(!N) break;
		l=s[N]*(N-1)-g[N];
		cout<<"Case "<<cs++<<": "<<(long long)floor(g[N]/100+1e-9)+1<<' '<<(long long)floor(l/100+1e-9)+1<<endl;
	}
	return 0;
}
