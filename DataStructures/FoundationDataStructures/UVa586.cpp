//LOOP 0...
#include <iostream>
#include <stack>
#include <sstream>
#include <cstring>
using namespace std;
const int maxn=15;
int T, res[maxn], mul, pos, dep, cnt;
bool f;
string ins;
stack<bool> s;
stack<int> num;
inline int init(){
	memset(res, 0, sizeof(res));
	mul=1;
	pos=0;
	dep=0;
	f=true;
}
void print(){
	cout<<"Runtime = ";
	bool flag=false;
	for(int i=12; i>0; i--){
		if(res[i]){
			if(!flag){
				if(res[i]>1) cout<<res[i]<<"*";
				cout<<'n';
				if(i>1) cout<<'^'<<i;
				flag=true;
			}else{
				cout<<'+';
				if(res[i]>1) cout<<res[i]<<"*";
				cout<<'n';
				if(i>1) cout<<'^'<<i;
			}
		}
	}
	if(!res[0]&&flag){
		cout<<endl;
		return;
	}
	if(!flag) cout<<res[0]<<endl;
	else cout<<'+'<<res[0]<<endl;
}
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		init();
		cin>>ins;
		dep++;
		while(dep){
			cin>>ins;
			if(ins=="LOOP"){
				dep++;
				string x;
				cin>>x;
				if(x=="n"){
					if(f){
						pos++;
						s.push(true);
					}else cnt++;
				}else{
					stringstream ss(x);
					int ops;
					ss>>ops;
					if(f&&!ops){
						f=false;
						cnt=0;
					}
					if(f){
						mul*=ops;
						s.push(false);
						num.push(ops);
					}else cnt++;
				}
			}else if(ins=="END"){
				dep--;
				if(!dep) continue;
				if(f){
					if(s.top()) pos--;
					else{
						mul/=num.top();
						num.pop();
					}
					s.pop();
				}else{
					cnt--;
					if(!cnt) f=true;
				}
			}else{
				int ops;
				cin>>ops;
				if(f) res[pos]+=ops*mul;
			}
		}
		cout<<"Program #"<<cs<<endl;
		print();
		cout<<endl;
	}
	return 0;
}
/*
2

BEGIN
OP 1
LOOP 0
LOOP n
END
END
END

BEGIN
OP 1
LOOP 0
LOOP n
END
END
LOOP n
OP 2
END
OP 3
END
 */
