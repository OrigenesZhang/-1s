#include <iostream>
#include <cstring>
using namespace std;
const int dir[3][2]={{0, -1}, {0, 1}, {1, 0}};
int d[80][80][7][3], table[80][80], N, K, cs=1, ans;
bool vis[80][80];
void dp(int x, int y, int cnt, int s){
    if(cnt>K) return;
    if(x==N&&y==N){
        ans=max(s, ans);
        return;
    }
    for(int i=0; i<3; i++){
        int nextx=x+dir[i][0], nexty=y+dir[i][1];
        if(nextx<=N&&nexty>0&&nexty<=N&&!vis[nextx][nexty]){
            vis[nextx][nexty]=true;
            if(table[nextx][nexty]<0&&d[nextx][nexty][cnt+1][i]<s+table[nextx][nexty]){
                d[nextx][nexty][cnt+1][i]=s+table[nextx][nexty];
                dp(nextx, nexty, cnt+1, s+table[nextx][nexty]);
            }else if(table[nextx][nexty]>=0&&d[nextx][nexty][cnt][i]<s+table[nextx][nexty]){
                d[nextx][nexty][cnt][i]=s+table[nextx][nexty];
                dp(nextx, nexty, cnt, s+table[nextx][nexty]);
            }
            vis[nextx][nexty]=false;
        }
    }
}
int main(){
    while(cin>>N>>K){
        if(!N&&!K) break;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                cin>>table[i][j];
        memset(vis, false, sizeof(vis));
        memset(d, 0x8f, sizeof(d));
        ans=-1<<30;
        vis[1][1]=true;//需要先初始化因为dp里面只修改所有非出发点的vis状态
        dp(1, 1, table[1][1]<0, table[1][1]);
        cout<<"Case "<<cs++<<": ";
        if(ans<-(1<<20)) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
