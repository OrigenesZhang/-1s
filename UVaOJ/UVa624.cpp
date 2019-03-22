#include <iostream>
#include <cstring>
using namespace std;
int N, n, dp[10010], t[25];//用time命名UVa会过不了编译lol
bool vis[25][10010];
int main(){
    while(cin>>N){
        cin>>n;
        memset(dp, 0, sizeof(dp));
        memset(vis, false, sizeof(vis));
        for(int i=1; i<=n; i++)
            cin>>t[i];
        for(int i=n; i>=1; i--)
            for(int j=N; j>=t[i]; j--)
                if(dp[j]<dp[j-t[i]]+t[i])
                    dp[j]=dp[j-t[i]]+t[i], vis[i][j]=true;
        for(int i=1, j=N; i<=n; i++){
            if(vis[i][j]){
                cout<<t[i]<<' ';
                j-=t[i];
            }
        }
        cout<<"sum:"<<dp[N]<<endl;
    }
    return 0;
}
