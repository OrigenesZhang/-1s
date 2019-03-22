#include <iostream>
#include <cstring>
using namespace std;
int dp[1<<12][4][4][4][4], t, n, idle, tot, table[5], S, C;
int dfs(int colour, int sz, int len){
    if(!len) return (colour!=C)&&(sz!=S);
    int state=0;
    for(int i=0; i<4; i++)
        state=(state<<3)+table[i];
    if(dp[state][S][C][sz][colour]!=-1) return dp[state][S][C][sz][colour];
    dp[state][S][C][sz][colour]=0;
    for(int i=0; i<n; i++){
        if(i==colour) continue;
        for(int j=1; j<4&&j<=table[i]; j++){
            if(j==sz) continue;
            table[i]-=j;
            dp[state][S][C][sz][colour]+=dfs(i, j, len-j);
            table[i]+=j;
        }
    }
    return dp[state][S][C][sz][colour];
}
int main(){
    cin>>t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin>>n;
        idle=tot=0;
        memset(table, 0, sizeof(table));
        for(int i=0; i<n; i++){
            cin>>table[i];
            idle=(idle<<3)+table[i];
            tot+=table[i];
        }
        if(!tot){
            cout<<1<<endl;
            continue;
        }
        int s=0;
        for(int i=0; i<n; i++){
            for(int j=1; j<4&&j<=table[i]; j++){
                C=i;
                S=j;
                table[i]-=j;
                s+=dfs(i, j, tot-j);
                table[i]+=j;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
