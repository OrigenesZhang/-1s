#include <iostream>
using namespace std;
int x, k, p, q, T;
int main(){
    cin>>T;
    while(T--){
        cin>>x>>k;
        if(x%k){
            q=x%k;
            p=k-q;
            cout<<p<<' '<<q<<endl;
        }else cout<<0<<' '<<k<<endl;
    }
    return 0;
}
