//Guangzhou regional 2003;
//bsearch the ans and do the judge greedily;
//Time complexity is not so important in is question;
#include <iostream>
using namespace std;
int n, data[31], ans=123456789, ans_stops=0, ans_data[31];
bool bsearch(int tlim){
	int ps[100], up=data[n-1], t=0, cur=1, stops=0, idx=0;
	while(idx<n&&t+(data[idx]-cur)*20<=tlim) idx++;
	while(idx!=n){
		int next_stop=data[idx];
		while(next_stop!=up+1&&t+(next_stop-data[idx])*20+(next_stop-cur)*4<=tlim)
            next_stop++;
		next_stop--;
		if(next_stop<data[idx]) return false;
		ps[stops++]=next_stop;
		t+=(next_stop-cur)*4;
		cur=next_stop;
		while(idx<n&&t+(data[idx]-cur)*20<=tlim) idx++;
		t+=10;
	}
	ans=tlim;
	ans_stops=stops;
	for(int i=0; i<stops; i++)
		ans_data[i]=ps[i];
	return true;
}
int main(){
	while(cin>>n){
		if(!n) break;
		for(int i=0; i<n; i++) cin>>data[i];
		int x=0, y=1000;
		while(y-x>1){
			int m=(x+y)/2;
			bsearch(m)?y=m:x=m;
		}
		bsearch(y);
		cout<<ans<<endl;
		cout<<ans_stops;
		for(int i=0; i<ans_stops; i++)
			cout<<' '<<ans_data[i];
		cout<<endl;
	}
	return 0;
}
