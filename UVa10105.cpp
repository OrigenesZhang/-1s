#include <iostream>
using namespace std;
int N, K, n;
int combination(){
    if(n==0||n==N) return 1;
    int c=1;
    for(int i=0; i<n; i++) c*=(N-i);
    for(int i=2; i<=n; i++) c/=i;
    return c;
}
int main(){
    while(cin>>N>>K){
        int c=1;
        for(int i=1; i<=K; i++){
            cin>>n;
            c*=combination();
            N-=n;
        }
        cout<<c<<endl;
    }
    return 0;
}
