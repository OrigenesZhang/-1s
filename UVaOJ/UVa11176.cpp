#include <iostream>
#include <iomanip>
using namespace std;
int n;
double p, dp[510][510], table[510];
int main(){
    cout<<fixed<<setprecision(6);
    while(cin>>n>>p){
        if(!n) break;
        table[0]=1;
        for(int i=1; i<=n; i++) table[i]=table[i-1]*p;
        for(int i=0; i<=n; i++) dp[0][i]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]=dp[i-1][j];
                if(j+1==i)
                    dp[i][j]-=table[j+1];
                else if(i>j+1)
                    dp[i][j]-=dp[i-j-2][j]*(1-p)*table[j+1];
            }
        }
        double e=0;
        for(int i=1; i<=n; i++)
            e+=(dp[n][i]-dp[n][i-1])*i;
        cout<<e<<endl;
    }
    return 0;
}
