#include <iostream>
using namespace std;
long long table[1010];
int L, cs=1;
long long combination(int n, int r){
    r=min(r, n-r);
    if(r<0) return 0;
    if(!r) return 1;
    long long p=1;
    for(int i=n; i>=n-r+1; i--) p*=i;
    for(int i=1; i<=r; i++) p/=i;
    return p;
}
int main(){
    for(int i=4; i<=1000; i+=2)
        table[i]=combination(i/2+3, i/2-2)-combination(i/2+1, i/2-4);
    while(cin>>L){
        if(!L) break;
        cout<<"Case "<<cs++<<": "<<table[L]<<endl;
    }
    return 0;
}
