#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, k, d[250], dp[250][35], s[250][250], mark[250][250], mid[250][250], cnt, cs=1;
void print(int l, int r) {
    if(l<1||r<1) return;
    print(mark[l][r]-1, r-1);
    cout<<"Depot "<<cnt++<<" at restaurant "<<mid[mark[l][r]][l]<<" serves restaurant";
    if(mark[l][r]==l) cout<<' '<<l<<endl;
    else cout<<"s "<<mark[l][r]<<" to "<<l<<endl;
}
int main() {
    while(cin>>n>>k){
        if(!n&&!k) break;
        for(int i=1; i<=n; i++)
            cin>>d[i];
        memset(s, 0, sizeof(s));
        for(int i=1; i<=n; i++){
            mid[i][i]=i;
            for(int j=i+1; j<=n; j++){
                int tmp=(i+j)/2;
                mid[i][j]=tmp;
                for(int u=i; u<=j; u++)
                    s[i][j]+=abs(d[u]-d[tmp]);
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                for(int u=1; u<=i; u++){
                    int tmp=dp[u-1][j-1]+s[u][i];
                    if(tmp<=dp[i][j]){
                        mark[i][j]=u;
                        dp[i][j]=tmp;
                    }
                }
            }
        }
        cout<<"Chain "<<cs++<<endl;
        cnt=1;
        print(n, k);
        cout<<"Total distance sum = "<<dp[n][k]<<endl;
        cout<<endl;
    }
    return 0;
}
