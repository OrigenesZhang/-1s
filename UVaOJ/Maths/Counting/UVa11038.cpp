#include <iostream>
using namespace std;
long long cnt(long long k){
    long long K=k, res=0, cur=1;
    int lowbit;
    while(K>=10){
        lowbit=K%10;
        K/=10;
        if(lowbit) res+=(K*cur);
        else res+=(K-1)*cur+k%cur+1;
        cur*=10;
    }
    return res;
}
int main(){
    long long m, n;
    while(cin>>m>>n){
        if(m<0) break;
        if(!m) cout<<cnt(n)+1<<endl;
        else cout<<cnt(n)-cnt(m-1)<<endl;
    }
    return 0;
}
