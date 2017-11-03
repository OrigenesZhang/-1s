#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string mmap[]={"16", "8", "4", "2", "1", "0"};
int N;
ll tot;
string s;
int main(){
	cin>>N;
	cout<<fixed<<setprecision(10);
	while(N--){
		cin>>s;
		ll tmp=1;
		for(int i=0; i<6; i++){
			if(s==mmap[i]){
				tot+=tmp;
				break;
			}
			tmp<<=1;
		}
	}
	cout<<double(tot)/16<<endl;
	return 0;
}
