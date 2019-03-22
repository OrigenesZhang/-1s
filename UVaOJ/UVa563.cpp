#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn=2*52*52+50;
const int inf=0x7f7f7f7f;
int P, S, A, B, s, t, a[maxn], p[maxn], cap[maxn][maxn], flow[maxn][maxn];
vector<int> e[maxn];
inline int get_index(int x, int y){
    return (x*S+y)<<1;
}
void read_graph(){
    s=0, t=1;
    memset(cap, 0, sizeof(cap));
    for(int i=0; i<=2*(S+1)*A; i++) e[i].clear();
    for(int i=1; i<=S; i++){
        for(int j=1; j<=A; j++){
            int index=get_index(i, j);
            cap[index][index+1]=1;
            e[index].push_back(index+1);
            cap[index+1][get_index(i-1, j)]=1;
            e[index+1].push_back(get_index(i-1, j));
            cap[index+1][get_index(i+1, j)]=1;
            e[index+1].push_back(get_index(i+1, j));
            cap[index+1][get_index(i, j-1)]=1;
            e[index+1].push_back(get_index(i, j-1));
            cap[index+1][get_index(i, j+1)]=1;
            e[index+1].push_back(get_index(i, j+1));
            if(i==1||j==1||i==S||j==A){
                cap[index+1][t]=1;
                e[index+1].push_back(t);
            }
        }
    }
    for(int i=0; i<B; i++){
        int x, y, index;
        cin>>x>>y;
        index=get_index(x, y);
        cap[s][index]=1;
        e[s].push_back(index);
    }
}
int main(){
    cin>>P;
    while(P--){
        cin>>S>>A>>B;
        read_graph();
        queue<int> q;
        memset(flow, 0, sizeof(flow));
        int f=0;
        for(;;){
            memset(a, 0, sizeof(a));
            a[s]=inf;
            q.push(s);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v : e[u]){
                    if(!a[v]&&cap[u][v]>flow[u][v]){
                        p[v]=u;
                        q.push(v);
                        a[v]=min(a[u], cap[u][v]-flow[u][v]);
                    }
                }
            }
            if(!a[t]) break;
            for(int u=t; u!=s; u=p[u]){
                flow[p[u]][u]+=a[t];
                flow[u][p[u]]-=a[t];
            }
            f+=a[t];
        }
        cout<<(f==B?"possible":"not possible")<<endl;
    }
    return 0;
}
