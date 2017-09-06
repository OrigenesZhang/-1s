#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=0x7f7f7f7f;
int d[105], w[105][105], fa[105], n, m, u, v, s, t;
bool inq[105];
void spfa(){
    queue<int> q;
    memset(d, 0x7f, sizeof(d));
    memset(inq, false, sizeof(inq));
    for(int i=1; i<=n; i++) fa[i]=s;
    d[s]=0;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;
        for(int y=1; y<=n; y++){
            if(d[y]>d[x]+w[x][y]){
                d[y]=d[x]+w[x][y];
                fa[y]=x;
                if(!inq[y]){
                    q.push(y);
                    inq[y]=true;
                }
            }
        }
    }
}
int main(){
    while(cin>>n){
        if(!n) break;
        cin>>m;
        memset(w, 0x7f, sizeof(w));
        for(int i=0; i<m; i++){
            cin>>u>>v;
            cin>>w[u][v];
            w[v][u]=w[u][v];
        }
        s=1;
        t=n;
        spfa();
        int res=0;
        if(d[t]==maxn){
            cout<<"Back to jail"<<endl;
            continue;
        }
        res+=d[t];
        for(int V=t; V!=s; V=fa[V]){
            w[fa[V]][V]=-w[fa[V]][V];
            w[V][fa[V]]=maxn;
        }
        s=n;
        t=1;
        spfa();
        if(d[t]==maxn){
            cout<<"Back to jail"<<endl;
            continue;
        }
        res+=d[t];
        cout<<res<<endl;
    }
    return 0;
}
