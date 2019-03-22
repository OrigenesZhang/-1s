#include <iostream>
#include <cstring>
using namespace std;
char B[30];
bool vis[30];
int cnt[30], T;
int main(){
	cin>>T;
	while(T--){
		cin>>B;
		memset(vis, false, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i<26; i++){
			if(!vis[i]){
				int j=i, n=0;
				do{
					vis[j]=true;
					j=B[j]-'A';
					n++;
				}while(j!=i);
				cnt[n]++;
			}
		}
		bool ok=true;
		for(int i=2; i<=26; i+=2)
			if(cnt[i]%2==1) ok=false;
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
