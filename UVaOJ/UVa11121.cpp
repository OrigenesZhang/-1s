#include <iostream>
#include <stack>
using namespace std;
stack<bool> s;
int N;
int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        int cur;
        cin>>cur;
        cout<<"Case #"<<i<<": ";
        if(!cur){
            cout<<0<<endl;
            continue;
        }
        while(cur){
            s.push(cur&1);
            cur>>=1;  //符号位不变
            cur*=(-1);
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
