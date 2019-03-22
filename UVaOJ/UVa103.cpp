#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[35][15], k, n, d[35];
bool G[35][35];
int dp(int i){
    int& ans=d[i];
    if(ans>0) return ans;
    ans=1;
    for(int j=1; j<=k; j++)
        if(G[i][j]) ans=max(ans, dp(j)+1);
    return ans;
}
void print_ans(int i){
    cout<<i<<' ';
    for(int j=1; j<=k; j++){
        if(G[i][j]&&d[i]==d[j]+1){
            print_ans(j);
            break;
        }
    }
}
int main(){
    while(cin>>k>>n){
        for(int i=1; i<=k; i++){
            for(int j=0; j<n; j++)
                cin>>v[i][j];
            sort(v[i], v[i]+n);
        }
        memset(G, false, sizeof(G));
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                if(i==j) continue;
                for(int K=0; K<n; K++)
                    if(v[i][K]>=v[j][K]) goto label;
                G[i][j]=true;
                label:;
            }
        }
        memset(d, 0, sizeof(d));
        int ans=dp(1), st=1;
        for(int i=2; i<=k; i++){
            int tmp=dp(i);
            if(tmp>ans) ans=tmp, st=i;
        }
        cout<<ans<<endl;
        print_ans(st);
        cout<<endl;//记得换行
    }
    return 0;
}
