#include <iostream>
#include <cstring>
using namespace std;
int m, n, T, d[10005], b[10005];
int dp(int t){
    if(d[t]!=-1) return d[t];
    if(t<m){
        d[t]=0;
        b[t]=t;
        return 0;
    }
    if(t<n){
        d[t]=dp(t-m)+1;
        b[t]=b[t-m];
    }
    else{
        dp(t-m);
        dp(t-n);
        if(b[t-m]<b[t-n]){
            d[t]=d[t-m]+1;
            b[t]=b[t-m];
        }else if(b[t-m]>b[t-n]){
            d[t]=d[t-n]+1;
            b[t]=b[t-n];
        }else{
            d[t]=max(d[t-n], d[t-m])+1;
            b[t]=b[t-m];
        }
    }
    return d[t];
}
int main(){
    while(cin>>m>>n>>T){
        memset(d, -1, sizeof(d));
        if(m>n) swap(m, n);
        cout<<dp(T);
        if(b[T]) cout<<' '<<b[T];
        cout<<endl;
    }
    return 0;
}
