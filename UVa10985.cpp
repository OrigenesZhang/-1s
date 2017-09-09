#include <iostream>
#include <cstring>
using namespace std;
const int inf=0x7f7f7f7f;
int N, n, m, d[130][130], buff[130];
int main(){
    cin>>N;
    for(int cs=1; cs<=N; cs++){
        cin>>n>>m;
        memset(d, 0x7f, sizeof(d));
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            d[u][v]=d[v][u]=1;
        }
        for(int i=0; i<n; i++) d[i][i]=0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                if(d[i][k]==inf) continue;
                for(int j=0; j<n; j++){
                    if(d[k][j]==inf) continue;
                    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
        int mmax=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(d[i][j]==inf) continue;
                int cnt=0;
                for(int k=0; k<n; k++)
                    if(d[i][j]==d[i][k]+d[k][j])
                        buff[cnt++]=k;
                int tot=0;
                for(int k=0; k<cnt; k++){
                    for(int u=k+1; u<cnt; u++){
                        int cur1=buff[k], cur2=buff[u];
                        if(d[cur1][cur2]==1&&d[i][cur1]!=d[i][cur2])
                            tot++;
                    }
                }
                mmax=max(mmax, tot);
            }
        }
        cout<<"Case #"<<cs<<": "<<mmax<<endl;
    }
    return 0;
}
