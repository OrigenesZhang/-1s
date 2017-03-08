#include <iostream>
#include <cstring>
using namespace std;
const int INF=1e9;
int dp[15][105], dir[3][2]={0, -1, -1, -1, 1, -1};
int m, n, a[15][105], path[15][105];
int main(){
    while(cin>>n>>m){
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>a[i][j];
        memset(path, -1, sizeof(path));
        for(int i=1; i<=n; i++)
            dp[i][m]=a[i][m];
        for(int i=1; i<=n; i++)
            for(int j=1; j<m; j++)
                dp[i][j]=INF;
        for(int i=m; i>=2; i--){
            for(int j=1; j<=n; j++){
                for(int k=0; k<3; k++){
                    int x=((j+dir[k][0]-1)%n+n)%n+1, y=i+dir[k][1];
                    if(dp[x][y]>dp[j][i]+a[x][y])
                        dp[x][y]=dp[j][i]+a[x][y], path[x][y]=j;
                    else if(dp[x][y]==dp[j][i]+a[x][y]&&path[x][y]>j)
                        path[x][y]=j;
                }
            }
        }
        int mmin=INF, cur;
        for(int i=1; i<=n; i++)
            if(mmin>dp[i][1])
                mmin=dp[i][1], cur=i;
        for(int i=1; i<=m; i++){
            if(i>1) cout<<' ';
            cout<<cur;
            cur=path[cur][i];
        }
        cout<<endl;
        cout<<mmin<<endl;
    }
    return 0;
}
