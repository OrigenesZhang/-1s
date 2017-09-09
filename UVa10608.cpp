#include <iostream>
using namespace std;
int p[30050], cnt[30050], n, m, T;
int Find(int x){
    return p[x]==x?x:p[x]=Find(p[x]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            p[i]=i;
            cnt[i]=1;
        }
        int mmax=1;
        for(int i=1; i<=m; i++){
            int u, v;
            cin>>u>>v;
            int x=Find(u), y=Find(v);
            if(x!=y){
                cnt[y]+=cnt[x];
                mmax=max(mmax, cnt[y]);
                p[x]=y;
            }
        }
        cout<<mmax<<endl;
    }
    return 0;
}
