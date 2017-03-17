#include <iostream>
#include <cstring>
using namespace std;
string s;
int N, R, C, dp[105][105], table[105][105], mmax;
int dfs(int x, int y){
    if(x<1||y<1||x>R||y>C) return -100;//写搜索的时候要注意小错误，不要想当然地作方表处理
    if(dp[x][y]!=-1) return dp[x][y];
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==j||i*j==-1) continue;
            if(table[x+i][y+j]>=table[x][y]) continue;
            dp[x][y]=max(dfs(x+i, y+j)+1, dp[x][y]);
        }
    }
    if(dp[x][y]==-1) dp[x][y]=1;
    if(dp[x][y]>mmax) mmax=dp[x][y];
    return dp[x][y];
}
int main(){
    cin>>N;
    while(N--){
        cin>>s>>R>>C;
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                cin>>table[i][j];
        memset(dp, -1, sizeof(dp));
        mmax=-1;
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                if(dp[i][j]==-1) dfs(i, j);
        cout<<s<<": "<<mmax<<endl;
    }
    return 0;
}
