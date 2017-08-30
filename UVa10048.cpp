//Floyd-Warshall algorithm
#include <iostream>
#include <cstring>
using namespace std;
int dist[105][105], C, S, Q, cs=1;
bool first=true;
int main(){
    ios_base::sync_with_stdio(false);
    while(cin>>C>>S>>Q){
        if(!C&&!S&&!Q) break;
        if(!first) cout<<endl;
        else first=false;
        cout<<"Case #"<<cs++<<endl;
        memset(dist, -1, sizeof(dist));
        for(int i=1; i<=C; i++)
            dist[i][i]=0;
        while(S--){
            int u, v, decibel;
            cin>>u>>v>>decibel;
            dist[u][v]=decibel;
            dist[v][u]=decibel;
        }
        for(int k=1; k<=C; k++){
            for(int i=1; i<=C; i++){
                for(int j=1; j<=C; j++){
                    if(dist[i][k]==-1||dist[k][j]==-1) continue;
                    if(dist[i][j]==-1) dist[i][j]=max(dist[i][k], dist[k][j]);
                    else dist[i][j]=min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
        while(Q--){
            int u, v;
            cin>>u>>v;
            if(dist[u][v]==-1) cout<<"no path"<<endl;
            else cout<<dist[u][v]<<endl;
        }
    }
    return 0;
}
