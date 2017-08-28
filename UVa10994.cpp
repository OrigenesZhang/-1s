#include <iostream>
using namespace std;
long long F(long long n){
    if(!n) return 0;
    return n%10?n%10:F(n/10);
}
long long S(long long p, long long q){
    if(p==q) return F(p);
    long long seg=q-p+1;
    long long res=0;
    if(seg<10){
        for(long long i=p; i<=q; i++)
            res+=F(i);
        return res;
    }
    res=seg/10*45;
    for(long long i=0; i<seg%10; i++)
        res+=(q-i)%10;
    return res+((p%10)?S(p/10+1, q/10):S(p/10, q/10));
}
int main(){
    long long p, q;
    while(cin>>p>>q){
        if(p<0&&q<0) break;
        cout<<S(p, q)<<endl;
    }
    return 0;
}
