#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
multiset<int> s;
int n, k, cur;
ll res;
inline void init(){
	s.clear();
	res=0;
}
int main(){
	while(cin>>n){
		if(!n) break;
		init();
		while(n--){
			cin>>k;
			for(int i=0; i<k; i++){
				cin>>cur;
				s.insert(cur);
			}
			auto it1=s.begin();
			int u=*it1;
			s.erase(it1);
			auto it2=prev(s.end());//erase只能erase正常的iterator不能erase reverse iterator
			int v=*it2;
			s.erase(it2);
			res+=ll(v-u);
		}
		cout<<res<<endl;
	}
	return 0;
}
