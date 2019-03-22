#include <iostream>
#include <cstring>
using namespace std;
string s;
long long dp[16][16], S;
int N;
bool vis[16][16];
int main(){
    while(cin>>s){
        N=s.length();
        memset(dp, 0, sizeof(dp));
        memset(vis, false, sizeof(vis));
        for(int i=0; i<N; i++){
            if(s.at(i)!='?'){
                for(int j=0; j<16; j++)
                    vis[i+1][j]=true;
                if(s.at(i)<='9') vis[i+1][s.at(i)-'0']=false;
                else vis[i+1][s.at(i)-'A'+10]=false;
            }
        }
        for(int i=1; i<=N; i++)
            if(!vis[1][i]) dp[1][i]=1;
        for(int i=2; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(vis[i][j]) continue;
                for(int k=1; k<=N; k++){
                    if(k>=j-1&&k<=j+1) continue;
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        S=0;
        for(int i=1; i<=N; i++)
            S+=dp[N][i];
        cout<<S<<endl;
    }
    return 0;
}
