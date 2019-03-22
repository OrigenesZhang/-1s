//第一组样例错了,应该输出Impossible.
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const long long inf=0x7f7f7f7f7f7f7f7f;
vector<int> e[105];
int N, M, D, K, flow[105][105], cap[105][105], p[105];
long long d[105], cost[105][105];
bool inq[105];
int main(){
    while(cin>>N>>M){
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));
        for(int i=1; i<=N; i++) e[i].clear();
        for(int i=0; i<M; i++){
            int u, v;
            cin>>u>>v;
            cin>>cost[u][v];
            cost[v][u]=cost[u][v];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cin>>D>>K;
        for(int i=1; i<=N; i++)
            for(int j:e[i])
                cap[i][j]=K;
        int s=0, t=N;
        cap[s][1]=D;
        queue<int> q;
        memset(flow, 0, sizeof(flow));
        int f=0;
        long long c=0;
        for(;;){
            memset(inq, false, sizeof(inq));
            memset(d, 0x7f, sizeof(d));
            d[s]=0;
            q.push(s);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                inq[u]=false;
                for(int v=0; v<=t; v++){
                    if(cap[u][v]>0&&flow[v][u]>0&&d[u]<d[v]+cost[v][u]){//后退修改
                        d[v]=d[u]-cost[v][u];
                        p[v]=u;
                        if(!inq[v]){
                            inq[v]=true;
                            q.push(v);
                        }
                    }else if(cap[u][v]>flow[u][v]&&d[v]>d[u]+cost[u][v]){
                        d[v]=d[u]+cost[u][v];
                        p[v]=u;
                        if(!inq[v]){
                            inq[v]=true;
                            q.push(v);
                        }
                    }
                }
            }
            if(d[t]==inf) break;
            long long a=inf;
            for(int u=t; u!=s; u=p[u])
                a=min(a, (long long)(cap[p[u]][u]-flow[p[u]][u]));
            for(int u=t; u!=s; u=p[u]){
                flow[p[u]][u]+=a;
                flow[u][p[u]]-=a;
            }
            c+=d[t]*a;
            f+=a;
        }
        if(f==D) cout<<c<<endl;
        else cout<<"Impossible."<<endl;
    }
    return 0;
}
