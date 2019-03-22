#include <iostream>
#include <cstring>
using namespace std;
int n, table[100], d[100], mmax, cs=1;
struct bottom{
    int l, w;
    bool operator < (const bottom& rhs) const{
        return (l<rhs.l&&w<rhs.w)||(w<rhs.l&&l<rhs.w);
    }
}b[100];
bool vis[100];
int dp(int cur){
    if(vis[cur]) return d[cur];
    vis[cur]=true;
    d[cur]=table[cur];
    for(int j=1; j<=3*n; j++)
        if(b[cur]<b[j]) d[cur]=max(dp(j)+table[cur], d[cur]);
    if(d[cur]>mmax) mmax=d[cur];
    return d[cur];
}
int main(){
    while(cin>>n){
        if(!n) break;
        for(int i=0; i<n; i++){
            int x, y, z;
            cin>>x>>y>>z;
            b[3*i+1]={x, y}, table[3*i+1]=z;
            b[3*i+2]={x, z}, table[3*i+2]=y;
            b[3*i+3]={y, z}, table[3*i+3]=x;
        }
        memset(vis, false, sizeof(vis));
        mmax=0;
        for(int i=1; i<=3*n; i++)
            if(!vis[i]) dp(i);
        cout<<"Case "<<cs++<<": maximum height = "<<mmax<<endl;
    }
    return 0;
}
