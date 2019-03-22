#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
bool primelst[65000];
int fast_pow(int x, int k, int p){
    long long product=1, base=x;
    while(k){
        if(k&1){
            product*=base;
            product%=p;
        }
        base*=base;
        base%=p;
        k>>=1;
    }
    return (int)product;
}
int main(){
    memset(primelst, true, sizeof(primelst));
    const int upp=sqrt(65000)+0.5;
    for(int i=2; i<=upp; i++)
        if(primelst[i])
            for(int j=i; i*j<65000; j++)
                primelst[i*j]=false;
    int n;
    while(cin>>n){
        if(!n) break;
        if(primelst[n]){
            cout<<n<<" is normal."<<endl;
            continue;
        }
        bool flag=true;
        for(int a=2; a<n; a++){
            if(fast_pow(a, n, n)!=a){
                cout<<n<<" is normal."<<endl;
                flag=false;
                break;
            }
        }
        if(flag) cout<<"The number "<<n<<" is a Carmichael number."<<endl;
    }
    return 0;
}
