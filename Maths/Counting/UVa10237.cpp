#include <iostream>
using namespace std;
int n, k;
long long dp1[40][1500], dp2[40][1500], res;//dp数组要开够
//两个dp数组分别储存黑格和白格的方案数
int main(){
    dp1[0][0]=dp2[1][0]=1;
    for(int i=1; i<=30; i++){
        int len=(((i+1)>>1)<<1)-1;
        dp1[i][0]=dp1[i-1][0];
        for(int j=1; j<=len; j++)
            dp1[i][j]=dp1[i-1][j]+(len-j+1)*dp1[i-1][j-1];
    }
    for(int i=2; i<=30; i++){
        int len=(i>>1)<<1;
        dp2[i][0]=dp2[i-1][0];
        for(int j=1; j<=len; j++)
            dp2[i][j]=dp2[i-1][j]+(len-j+1)*dp2[i-1][j-1];
    }
    while(cin>>n>>k){
        if(!n&&!k) break;
        res=0;
        for(int i=0; i<=k; i++)
            res+=dp1[n][i]*dp2[n][k-i];
        cout<<res<<endl;
    }
    return 0;
}
