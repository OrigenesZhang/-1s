#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxc=9;
const int maxk=100;
const int LIMIT=10000;
set<int> values[maxc];
int C, X[maxc], k[maxc], Y[maxc][maxk], a[maxc];
vector<long long> sol;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
long long china(int n, int* a, int* m){
	long long M=1, d, y, x=0;
	for(int i=0; i<n; i++) M*=m[i];
	for(int i=0; i<n; i++){
		long long w=M/m[i];
		exgcd(m[i], w, d, d, y);
		x=(x+y*w*a[i])%M;
	}
	return (x+M)%M;
}
void solve_enum(int S, int bc){
	for(int c=0; c<C; c++){
		if(c!=bc){
			values[c].clear();
			for(int i=0; i<k[c]; i++) values[c].insert(Y[c][i]);
		}
	}
	for(int t=0; S!=0; t++){
		for(int i=0; i<k[bc]; i++){
			long long n=(long long)X[bc]*t+Y[bc][i];
			if(!n) continue;
			bool ok=true;
			for(int c=0; c<C; c++){
				if(c!=bc){
					if(!values[c].count(n%X[c])){
						ok=false;
						break;
					}
				}
			}
			if(ok){
				printf("%lld\n", n);
				if(!--S) break;
			}
		}
	}
}
void dfs(int dep){
	if(dep==C) sol.push_back(china(C, a, X));
	else{
		for(int i=0; i<k[dep]; i++){
			a[dep]=Y[dep][i];
			dfs(dep+1);
		}
	}
}
void solve_china(int S){
	sol.clear();
	dfs(0);
	sort(sol.begin(), sol.end());
	long long M=1;
	for(int i=0; i<C; i++) M*=X[i];
	vector<long long> ans;
	for(int i=0; S!=0; i++){
		for(int j=0; j<sol.size(); j++){
			long long n=M*i+sol[j];
			if(n>0){
				printf("%lld\n", n);
				if(!--S) break;
			}
		}
	}
}
int main(){
	int S;
	while(scanf("%d%d", &C, &S)==2){
		if(!C) break;
		long long tot=1;
		int bestc=0;
		for(int c=0; c<C; c++){
			scanf("%d%d", &X[c], &k[c]);
			tot*=k[c];
			for(int i=0; i<k[c]; i++) scanf("%d", &Y[c][i]);
			sort(Y[c], Y[c]+k[c]);
			if(k[c]*X[bestc]<k[bestc]*X[c]) bestc=c;
		}
		if(tot>LIMIT) solve_enum(S, bestc);
		else solve_china(S);
		printf("\n");
	}
	return 0;
}
