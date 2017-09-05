#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=0x7f7f7f7f;
const int toright=105;
int flow[250][250], cap[250][250], p[250], a[250], N, M, B, D;
void read_graph(){
    memset(cap, 0, sizeof(cap));
    for(int i=1; i<=N; i++)
        cin>>cap[i][i+toright];//拆点
    cin>>M;
    for(int i=0; i<M; i++){
        int I, J, C;
        cin>>I>>J>>C;
        cap[I+toright][J]=C;
    }
    cin>>B>>D;
    for(int i=0; i<B; i++){
        int cur;
        cin>>cur;
        cap[0][cur]=maxn;
    }
    for(int i=0; i<D; i++){
        int cur;
        cin>>cur;
        cap[cur+toright][N+1]=maxn;
    }
}
int main(){
    while(cin>>N){
        read_graph();
        memset(flow, 0, sizeof(flow));//Edmonds-Karp
        memset(p, 0, sizeof(p));
        queue<int> q;
        int f=0, t=N+1;
        N+=toright;
        for(;;){
            memset(a, 0, sizeof(a));
            a[0]=maxn;
            q.push(0);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v=1; v<=N; v++){
                    if(!a[v]&&cap[u][v]>flow[u][v]){
                        p[v]=u;
                        q.push(v);
                        a[v]=min(a[u], cap[u][v]-flow[u][v]);
                    }
                }
            }
            if(!a[t]) break;
            for(int u=t; u!=0; u=p[u]){
                flow[p[u]][u]+=a[t];
                flow[u][p[u]]-=a[t];
            }
            f+=a[t];
        }
        cout<<f<<endl;
    }
    return 0;
}
