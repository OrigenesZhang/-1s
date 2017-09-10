#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int inf=0x3f3f3f3f;
typedef pair<int, int> pii;
int T, A, B, M, L, K, dp[110][15], d[110][110];
bool inq[110][15];
int main(){
    cin>>T;
    while(T--){
        cin>>A>>B>>M>>L>>K;
        memset(d, 0x3f, sizeof(d));
        for(int i=0; i<M; i++){
            int u, v;
            cin>>u>>v;
            cin>>d[u][v];
            d[v][u]=d[u][v];
        }
        for(int i=1; i<=A+B; i++) d[i][i]=0;
        for(int k=1; k<=A; k++)//只算能飞的最短路
            for(int i=1; i<=A+B; i++)
                for(int j=1; j<=A+B; j++)
                    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
        queue<pii> q;
        memset(inq, false, sizeof(inq));
        memset(dp, 0x3f, sizeof(dp));
        dp[A+B][0]=0;
        q.push(make_pair(A+B, 0));
        while(!q.empty()){
            int x=q.front().first;
            int k=q.front().second;
            q.pop();
            inq[x][k]=false;
            for(int i=1; i<=A+B; i++){
                if(dp[i][k]>dp[x][k]+d[x][i]){
                    dp[i][k]=dp[x][k]+d[x][i];
                    if(!inq[i][k]){
                        q.push(make_pair(i, k));
                        inq[i][k]=true;
                    }
                }
                if(d[x][i]<=L&&k<K&&dp[x][k]<dp[i][k+1]){
                    dp[i][k+1]=dp[x][k];
                    if(!inq[i][k+1]){
                        q.push(make_pair(i, k+1));
                        inq[i][k+1]=true;
                    }
                }
            }
        }
        int mmin=inf;
        for(int i=0; i<=K; i++) mmin=min(mmin, dp[1][i]);
        cout<<mmin<<endl;
    }
    return 0;
}
