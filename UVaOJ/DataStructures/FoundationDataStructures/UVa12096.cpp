//模拟[不过学了下inserter怎么用还是挺好的]
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef set<int> Set;
const string ops[]={"PUSH", "DUP", "UNION", "INTERSECT", "ADD"};
map<Set, int> mmap;
vector<Set> v;
stack<int> s;
string op;
int T, N;
int Hash(Set s){
	if(mmap[s]) return mmap[s];
	v.push_back(s);
	return mmap[s]=int(v.size())-1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		if(!s.empty()){
			stack<int> tmp;
			swap(s, tmp);
		}
		while(N--){
			cin>>op;
			if(op==ops[0]) s.push(Hash(Set()));
			else if(op==ops[1]){
				int u=s.top();
				s.push(u);
			}else{
				Set s1=v[s.top()];
				s.pop();
				Set s2=v[s.top()];
				s.pop();
				Set cur;
				if(op==ops[2]) set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(cur, cur.end()));
				else if(op==ops[3]) set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(cur, cur.end()));
				else{
					cur=s2;
					cur.insert(Hash(s1));
				}
				s.push(Hash(cur));
			}
			cout<<v[s.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}
