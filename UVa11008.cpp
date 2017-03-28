#include <iostream>
#include <cstring>
using namespace std;
int x[20], y[20], table[20][20], n, m, d[100000], cs;
inline int Cnt(int cur){
    int cnt=0;
    for(int i=0; i<n; i++)
        if((1<<i)&cur) cnt++;
    return cnt;
}
int dp(int cur){
    int cnt=Cnt(cur);
    if (cnt<=n-m) return d[cur]= 0;
    else if(cnt==1) return d[cur]= 1;
    else if(d[cur]>-1) return d[cur];
    d[cur]=1<<30;
    for(int i=0; i<n; i++){
        if((1<<i)&cur){
            for(int j=i+1; j<n; j++){
                if((1<<j)&cur){
                    int pos=cur&(table[i][j]^((1<<n)-1));
                    d[cur]=min(d[cur], dp(pos) + 1);
                }
            }
        }
    }
    return d[cur];
}
int main(){
    cin>>cs;
    for(int u=1; u<=cs; u++){
        cin>>n>>m;
        memset(d, -1, sizeof(d));
        memset(table, 0, sizeof(table));
        for(int i=0; i<n; i++)
            cin>>x[i]>>y[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                for(int k=n-1; k>=0; k--){
                    table[i][j]<<=1;
                    if((x[j]-x[i])*(y[k]-y[i])==(x[k]-x[i])*(y[j]-y[i])) table[i][j]++;
                }
            }
        }
        cout<<"Case #"<<u<<':'<<endl;
        cout<<dp((1<<n)-1)<<endl;
        if(u!=cs) cout<<endl;
    }
    return 0;
}
