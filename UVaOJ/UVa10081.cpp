#include <iostream>
#include <iomanip>
using namespace std;
double dp[105][10];
int k, n;
int main(){
    while(cin>>k>>n){
        if(k<2){
            cout<<"100.00000"<<endl;
            continue;
        }
        for(int i=0; i<=k; i++)
            dp[1][i]=100.0/(k+1);
        for(int i=2; i<=n; i++){
            for(int j=0; j<=k; j++){
                if(!j)
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])/(k+1);
                else if(j==k)
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])/(k+1);
                else
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])/(k+1);
            }
        }
        double tot=0;
        for(int i=0; i<=k; i++) tot+=dp[n][i];
        cout<<fixed<<setprecision(5);
        cout<<tot<<endl;
    }
    return 0;
}
