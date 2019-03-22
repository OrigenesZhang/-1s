#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn=1e+18+100;
const string Suit="CDHS";
const string Rank="23456789AJKQT";
bool vis[16][16][16][16][5];
long long d[16][16][16][16][5], K;
double da[16][16][16][16][5];
int cs=1, N;
long long dp(int f4, int f3, int f2, int f1, int lst){
	if(vis[f4][f3][f2][f1][lst])
		return d[f4][f3][f2][f1][lst];
	vis[f4][f3][f2][f1][lst]=true;
	long long& res=d[f4][f3][f2][f1][lst];
	double& check=da[f4][f3][f2][f1][lst];
	if(!(f4+f3+f2+f1)){
		res=1;
		check=1;
		return 1;
	}
	if(f4>0){
		res+=4*f4*dp(f4-1, f3+1, f2, f1, 4);
		check+=4*f4*da[f4-1][f3+1][f2][f1][4];
	}
	res=min(res, maxn);
	if(check>maxn) return res;
	if(f3>0){
		if(lst==4){
			res+=3*(f3-1)*dp(f4, f3-1, f2+1, f1, 3);
			check+=3*(f3-1)*da[f4][f3-1][f2+1][f1][3];
		}else{
			res+=3*f3*dp(f4, f3-1, f2+1, f1, 3);
			check+=3*f3*da[f4][f3-1][f2+1][f1][3];
		}
	}
	res=min(res, maxn);
	if(check>maxn) return res;
	if(f2>0){
		if(lst==3){
			res+=2*(f2-1)*dp(f4, f3, f2-1, f1+1, 2);
			check+=2*(f2-1)*da[f4][f3][f2-1][f1+1][2];
		}else{
			res+=2*f2*dp(f4, f3, f2-1, f1+1, 2);
			check+=2*f2*da[f4][f3][f2-1][f1+1][2];
		}
	}
	res=min(res, maxn);
	if(check>maxn) return res;
	if(f1>0){
		if(lst==2){
			res+=(f1-1)*dp(f4, f3, f2, f1-1, 1);
			check+=(f1-1)*da[f4][f3][f2][f1-1][1];
		}else{
			res+=f1*dp(f4, f3, f2, f1-1, 1);
			check+=f1*da[f4][f3][f2][f1-1][1];
		}
	}
	res=min(res, maxn);
	return res;
}
int main(){
	while(cin>>N>>K){
		if(!N&&!K) break;
		string card;
		int deck[60];
		for(int i=0; i<N; i++){
			cin>>card;
			deck[i]=0;
			switch(card.at(0)){
				case 'T':{
					deck[i]=12;
					break;
				}
				case 'J':{
					deck[i]=9;
					break;
				}
				case 'Q':{
					deck[i]=11;
					break;
				}
				case 'K':{
					deck[i]=10;
					break;
				}
				case 'A':{
					deck[i]=8;
					break;
				}
				default: deck[i]=card.at(0)-'2';
			}
			deck[i]<<=2;
			switch(card.at(1)){
				case 'C': break;
				case 'D':{
					deck[i]++;
					break;
				}
				case 'H':{
					deck[i]+=2;
					break;
				}
				default: deck[i]+=3;
			}
		}
		int res[60];
		bool nf=false;
		K--;
		for(int i=0; i<N; i++){
			sort(deck+i, deck+N);
			res[i]=-1;
			for(int j=i; j<N; j++){
				int cur=deck[j];
				int cnt[13]={};
				int f[10]={};
				if(i&&cur>>2==res[i-1]>>2)
					continue;
				for(int k=i; k<N; k++)
					cnt[deck[k]>>2]++;
				int lst=cnt[cur>>2]--;
				for(int k=0; k<13; k++)
					f[cnt[k]]++;
				long long sol=dp(f[4], f[3], f[2], f[1], lst);
				if(da[f[4]][f[3]][f[2]][f[1]][lst]>K){
					swap(deck[i], deck[j]);
					res[i]=cur;
					break;
				}else K-=sol;
			}
			if(res[i]==-1){
				nf=true;
				break;
			}
		}
		cout<<"Case "<<cs++<<":";
		if(nf){
			cout<<" Not Found"<<endl;
			continue;
		}
		for(int i=0; i<N; i++)
			cout<<' '<<Rank[res[i]>>2]<<Suit[res[i]&3];
		cout<<endl;
	}
	return 0;
}
