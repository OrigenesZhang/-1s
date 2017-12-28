#include <iostream>
#include <stack>
using namespace std;
const int maxn=1234;
int N, a[maxn], p, q;
stack<int> s;
bool read(){
	for(int i=1; i<=N; i++){
		cin>>a[i];
		if(!a[i]) return false;
	}
	return true;
}
int main(){
	while(cin>>N){
		if(!N) break;
		while(read()){
			if(!s.empty()){
				stack<int> tmp;
				swap(tmp, s);
			}
			p=q=1;
			bool flag=true;
			while(q<=N){
				if(p==a[q]){
					p++;
					q++;
				}else if(!s.empty()&&s.top()==a[q]){
					s.pop();
					q++;
				}else if(p<=N) s.push(p++);
				else{
					flag=false;
					break;
				}
			}
			cout<<(flag?"Yes":"No")<<endl;
		}
		cout<<endl;
	}
	return 0;
}
