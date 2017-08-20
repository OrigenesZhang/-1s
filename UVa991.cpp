#include <bits/stdc++.h>
using namespace std;
int f[15], N;
int main(){
    memset(f, 0, sizeof(f));
    f[0]=f[1]=1;
    for(int i=2; i<=10; i++)
        for(int j=0; j<i; j++)
            f[i]+=f[i-j-1]*f[j];
    bool first=true;
    while(cin>>N){
        if(!first) cout<<endl;
        first=false;
        cout<<f[N]<<endl;
    }
    return 0;
}
