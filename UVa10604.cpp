#include <iostream>
#include <cstring>
using namespace std;
const int power[]={0, 1, 10, 100, 1000, 10000, 100000};
int d[1000000], T, m, k, table[10][10], heat[10][10];
bool vis[1000000];
string s;
inline bool check(int cur){
    int cnt=0;
    for(int i=1; i<=m; i++){
        cnt+=(cur%10>0);
        cur/=10;
    }
    return cnt<=1;
}
int dp(int cur){
    if(vis[cur]) return d[cur];
    if(check(cur)) return 0;
    vis[cur]=true;
    d[cur]=1<<30;
    for(int i=1; i<=m; i++){
        if(!(cur/power[i]%10)) continue;
        for(int j=1; j<=m; j++){
            if(!(cur/power[j]%10)) continue;
            if(i==j&&cur/power[i]%10==1) continue;
            d[cur]=min(d[cur], dp(cur-power[i]-power[j]+power[table[i][j]])+heat[i][j]);
        }
    }
    return d[cur];
}
int main(){
    cin>>T;
    while(T--){
        cin>>m;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=m; j++)
                cin>>table[i][j]>>heat[i][j];
        cin>>k;
        int tmp=0;
        for(int i=1; i<=k; i++){
            int cur;
            cin>>cur;
            tmp+=power[cur];
        }
        memset(vis, false, sizeof(vis));
        cout<<dp(tmp)<<endl;
        cin>>s;
    }
    return 0;
}
//样例有错坑了我半天
