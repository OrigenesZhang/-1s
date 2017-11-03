#include <bits/stdc++.h>
using namespace std;
map<string, int> value;
void init(){
	value["red"]=1;
	value["yellow"]=2;
	value["green"]=3;
	value["brown"]=4;
	value["blue"]=5;
	value["pink"]=6;
	value["black"]=7;
}
int N, cnt[15], res;
int main(){
	init();
	cin>>N;
	for(int i=0; i<N; i++){
		string s;
		cin>>s;
		cnt[value[s]]++;
	}
	while(cnt[1]){
		cnt[1]--;
		res++;
		bool flag=false;
		for(int i=7; i>=2; i--)
			if(cnt[i]){
				res+=i;
				flag=true;
				break;
			}
		if(!flag){
			cout<<res<<endl;
			return 0;
		}
	}
	for(int i=2; i<=7; i++)
		if(cnt[i]) res+=i;
	cout<<res<<endl;
	return 0;
}
