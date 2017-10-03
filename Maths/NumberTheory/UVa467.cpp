#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
string s;
int vis[7200], cs=1, t, mmin, Time, cnt;
int main(){
	while(getline(cin, s)){
		memset(vis, 0, sizeof(vis));
		stringstream ss(s);
		mmin=Time=inf;
		cnt=0;
		while(ss>>t){
			mmin=min(mmin, t);
			int base=-t;
			cnt++;
			while(base<=3600){
				base+=t;
				for(int i=base+1, j=0; j<t-5; i++, j++)
					vis[i]++;
				base+=t;
			}
		}
		for(int i=mmin; i<=3601; i++){
			if(vis[i]==cnt){
				Time=i;
				break;
			}
		}
		Time--;
		cout<<"Set "<<cs++;
		if(Time<=3600) cout<<" synchs again at "<<Time/60<<" minute(s) and "<<Time%60<<" second(s) after all turning green."<<endl;
		else cout<<" is unable to synch after one hour."<<endl;
	}
	return 0;
}
