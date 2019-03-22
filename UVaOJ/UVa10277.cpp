#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}
int main(){
    long long p, q;
    while(cin>>p>>q){
        if(!p&&!q) break;
        if(!p){
            cout<<"0 2"<<endl;
            continue;
        }
        long long g=gcd(p, q);
        p/=g;
        q/=g;
        if(p==1&&q==1){
            cout<<"2 0"<<endl;
            continue;
        }
        long long tot, red;
        for(tot=2; tot<=50000; tot++){
            if(!(tot*(tot-1)%q)){
                long long tmp=tot*(tot-1)/q*p;
                red=sqrt(tmp+0.5)+0.5;
                if(red*(red-1)==tmp&&red!=0){
                    cout<<red<<' '<<tot-red<<endl;
                    goto label;
                }
            }
        }
        cout<<"impossible"<<endl;
        label:;
    }
    return 0;
}
