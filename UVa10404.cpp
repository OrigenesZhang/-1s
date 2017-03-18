#include <iostream>
#include <cstring>
using namespace std;
int n, m, package[15];
bool dp[1000005];
int main(){
    while(cin>>n>>m){
        for(int i=1; i<=m; i++)
            cin>>package[i];
        memset(dp, false, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i-package[j]>=0&&!dp[i-package[j]]){
                    dp[i]=true;
                    break;
                }
            }
        }
        if(dp[n]) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }
    return 0;
}
