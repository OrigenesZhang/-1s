#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int>> mmap;
int n, m, k, v;
int main(){
	while(cin>>n>>m){
		mmap.clear();
		for(int i=1; i<=n; i++){
			int tmp;
			cin>>tmp;
			mmap[tmp].push_back(i);
		}
		while(m--){
			cin>>k>>v;
			if(mmap[v].size()<k) cout<<0<<endl;
			else cout<<mmap[v][k-1]<<endl;
		}
	}
	return 0;
}
