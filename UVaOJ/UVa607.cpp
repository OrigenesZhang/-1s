#include <iostream>
#include <cstring>
using namespace std;
int dp[1005][1005], s[1005], t[1005], n, L, C, cs=1;
bool vis[1005][1005];
inline int DI(int l, int r){
    int tmp=L-s[r]+s[l];
    if(!tmp) return 0;
    if(tmp<=10) return -C;
    return (tmp-10)*(tmp-10);
}
int main(){
    while(cin>>n){
        if(!n) break;
        cin>>L>>C;
        memset(vis, false, sizeof(vis));
        s[0]=0;
        int cnt=1, prev=0;
        for(int i=1; i<=n; i++){
            cin>>t[i];
            s[i]=s[i-1]+t[i];
            if(s[i]-prev>L){
                prev=s[i-1];
                cnt++;
            }
        }
        if(cs>1) cout<<endl;
        cout<<"Case "<<cs++<<':'<<endl;
        cout<<"Minimum number of lectures: "<<cnt<<endl;
        dp[0][0]=0;
        vis[0][0]=true;
        for(int i=1; i<=cnt; i++){
            dp[i][0]=0;
            vis[i][0]=true;
            for(int j=i; j<=n&&s[j]<=i*L; j++){
                vis[i][j]=true;
                dp[i][j]=1<<30;
                for(int k=j-1; s[j]-s[k]<=L&&k>=0; k--){
                    if(!vis[i-1][k]) continue;
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+DI(k, j));
                }
            }
        }
        cout<<"Total dissatisfaction index: "<<dp[cnt][n]<<endl;
    }
    return 0;
}
