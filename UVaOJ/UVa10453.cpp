#include <iostream>
#include <cstring>
using namespace std;
int dp[1005][1005], N;
bool vis[1005][1005];
string s;
int dfs(int l, int r){
    if(l>=r) return dp[l][r]=0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r]=true;
    if(s.at(l)==s.at(r)) dp[l][r]=dfs(l+1, r-1);
    return dp[l][r]=min(dp[l][r], min(dfs(l+1, r), dfs(l, r-1))+1);
}
void print(int l, int r){
    if(l>r) return;
    if(l==r){
        cout<<s.at(l);
        return;
    }
    if(s.at(l)==s.at(r)){
        cout<<s.at(l);
        print(l+1, r-1);
        cout<<s.at(l);
    }else if(dp[l][r]==dp[l+1][r]+1){
        cout<<s.at(l);
        print(l+1, r);
        cout<<s.at(l);
    }else{
        cout<<s.at(r);
        print(l, r-1);
        cout<<s.at(r);
    }
}
int main(){
    while(getline(cin, s)){
        N=s.length()-1;
        memset(vis, false, sizeof(vis));
        memset(dp, 0x3f, sizeof(dp));
        dfs(0, N);
        cout<<dp[0][N]<<' ';
        print(0, N);
        cout<<endl;
    }
    return 0;
}
