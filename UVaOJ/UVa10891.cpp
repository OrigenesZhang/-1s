#include <iostream>
#include <cstring>
using namespace std;
const int minn=-(1<<30);
int d[105][105], num[105], s[105][105], n;
bool vis[105][105];
int dp(int l, int r){
    if(l>r) return 0;
    if(vis[l][r]) return d[l][r];
    vis[l][r]=true;
    if(l==r) return d[l][r]=num[l];
    d[l][r]=minn;
    for(int i=1; i<=r-l+1; i++)
        d[l][r]=max(d[l][r], max(s[l][l+i-1]-dp(l+i, r), s[r-i+1][r]-dp(l, r-i)));
    return d[l][r];
}
int main(){
    while(cin>>n){
        if(!n) break;
        for(int i=1; i<=n; i++)
            cin>>num[i];
        memset(vis, false, sizeof(vis));
        memset(s, 0, sizeof(s));
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
                for(int k=i; k<=j; k++)
                    s[i][j]+=num[k];
        cout<<dp(1, n)<<endl;
    }
    return 0;
}
