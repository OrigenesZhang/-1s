#include <iostream>
using namespace std;
int dp[27][27][10005], s[27][10005], L, S, cs=1;
int main(){
    dp[0][0][0]=1;
    for(int i=1; i<=26; i++){
        int upp=i*26;
        for(int k=1; k<=upp; k++){
            for(int j=1; j<=min(k, 26); j++){
                for(int u=0; u<j; u++)
                    dp[i][j][k]+=dp[i-1][u][k-j];
                s[i][k]+=dp[i][j][k];
            }
        }
    }
    while(cin>>L>>S){
        if(!L) break;
        cout<<"Case "<<cs++<<": "<<s[min(L, 26)][S]<<endl;
    }
    return 0;
}
