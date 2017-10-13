#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100000;
typedef pair<int, int> pii;
pii s[maxn+100];
int a, c, n;
int main(){
	s[0]=make_pair(0, 0);
	while(cin>>c>>n){
		if(!c) break;
		for(int i=1; i<=n; i++){
			cin>>a;
			s[i]=make_pair((s[i-1].first+a)%c, i);
		}
		sort(s+1, s+n+1);
		if(!s[1].first){
			for(int i=1; i<=s[1].second; i++)
				cout<<i<<' ';
			cout<<endl;
			continue;
		}
		for(int i=2; i<=n; i++){
			if(s[i].first==s[i-1].first){
				for(int j=s[i-1].second+1; j<=s[i].second; j++)
					cout<<j<<' ';
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}
