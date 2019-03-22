#include <iostream>
using namespace std;
int k, n, t, p;
long long combinaton(long long n, long long r){
    r=min(r, n-r);
    long long c=1;
    for(long long i=1; i<=r; i++)
        c=c*(n-i+1)/i;
    return c;
}
int main(){
    cin>>k;
    while(k--){
        cin>>n>>t>>p;
        int r=t-n*p;
        if(r<0){
            cout<<0<<endl;
            continue;
        }
        cout<<combinaton(n+r-1, n-1)<<endl;
    }
    return 0;
}
