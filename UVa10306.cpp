#include <iostream>
#include <cstring>
using namespace std;
int dp[305][305], w1[50], w2[50], n, mmax;
int main(){
    cin>>n;
    while(n--){
        int m, S;
        cin>>m>>S;
        for(int i=0; i<m; i++)
            cin>>w1[i]>>w2[i];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i=0; i<m; i++)
            for(int v1=w1[i]; v1<=S; v1++)
                for(int v2=w2[i]; v2<=S; v2++)
                    if(dp[v1-w1[i]][v2-w2[i]]>=0){
                        if(dp[v1][v2]<0) dp[v1][v2]=dp[v1-w1[i]][v2-w2[i]]+1;
                        else dp[v1][v2]=min(dp[v1][v2], dp[v1-w1[i]][v2-w2[i]]+1);
                    }
        mmax=-1;
        for(int i=0; i<=S; i++)
            for(int j=0; j<=S; j++)
                if(i*i+j*j==S*S&&dp[i][j]>=0){
                    if(mmax>=0) mmax=min(mmax, dp[i][j]);
                    else mmax=dp[i][j];
                }
        if(mmax>=0) cout<<mmax<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}
