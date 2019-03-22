#include <iostream>
#include <cstring>
using namespace std;
char s1[65], s2[65], s3[65];
int dp1[65][65][65], dp2[65][65][65], dp[65][65][65], T;
const int MOD=10007;
int main(){
    cin>>T;
    while(T--){
        cin>>s1+1>>s2+1>>s3+1;
        int len1, len2, len3;
        len1=strlen(s1+1), len2=strlen(s2+1), len3=strlen(s3+1);
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=len1; i++)
            for(int j=0; j<=len2; j++)
                dp1[i][j][0]=dp2[i][j][0]=dp[i][j][0]=1;
        for(int k=1; k<=len3; k++){
            for(int i=0; i<=len1; i++){
                for(int j=0; j<=len2; j++){
                    if(i){
                        dp1[i][j][k]=dp1[i-1][j][k];//若s1[i]!=s3[k]且s2[j]!=s3[k],那么事实上dp[i-1][j][k]==dp[i][j][k]==dp[i][j-1][k],直接用dp往上加会重复
                        if(s1[i]==s3[k]) dp1[i][j][k]+=dp[i-1][j][k-1];
                        dp1[i][j][k]%=MOD;
                    }
                    if(j){
                        dp2[i][j][k]=dp2[i][j-1][k];
                        if(s2[j]==s3[k]) dp2[i][j][k]+=dp[i][j-1][k-1];
                        dp2[i][j][k]%=MOD;
                    }
                    dp[i][j][k]=(dp1[i][j][k]+dp2[i][j][k])%MOD;
                }
            }
        }
        cout<<dp[len1][len2][len3]<<endl;
    }
    return 0;
}
