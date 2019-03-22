#include <iostream>
using namespace std;
const unsigned long long maxn=(unsigned long long)1<<63;
const string sign="+-";
unsigned long long s[110], cur, w[110], N, Q;
int cnt, K, tot;
void init(){
	while(cur<maxn){
		cur=(s[cnt++]<<1)+1;
		s[cnt]=s[cnt-1]+cur;
		w[cnt]=cur;
	}
	w[++cnt]=maxn+(maxn-1);
	s[cnt]=w[cnt];
}
int main(){
	init();
	while(cin>>N>>K){
		if(!N&&!K) break;
		tot=0;
		while(++tot<=cnt)
			if(N<=s[tot]) break;
		cout<<tot;
		for(int i=1; i<=tot; i++)
			cout<<' '<<w[i];
		cout<<endl;
		while(K--){
			cin>>Q;
			bool minus=true;
			int tmp=tot;
			while(Q){
				for( ; tmp>=1; tmp--){
					if(Q<=s[tmp]&&Q>s[tmp-1]){
						cout<<w[tmp];
						if(Q>w[tmp]){
							Q-=w[tmp];
							cout<<sign.at(!minus);
						}else if(Q<w[tmp]){
							Q=w[tmp]-Q;
							cout<<sign.at(minus);
							minus^=1;
						}else Q=0;
						tmp--;
						break;
					}
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
