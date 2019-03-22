#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int maxn=0x7f7f7f7f;
map<string, int> conv;
int T, n, m, k, flow[501][501], cap[501][501], a[501], p[501], s, t, cnt;
string str;
int EK(){
    queue<int> q;
    memset(flow, 0, sizeof(flow));
    int f=0;
    for(;;){
        memset(a, 0, sizeof(a));
        a[s]=maxn;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=1; v<=500; v++){
                if(!a[v]&&cap[u][v]>flow[u][v]){
                    p[v]=u;
                    q.push(v);
                    a[v]=min(a[u], cap[u][v]-flow[u][v]);
                }
            }
        }
        if(!a[t]) break;
        for(int u=t; u!=s; u=p[u]){
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        f+=a[t];
    }
    return f;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        conv.clear();
        s=0, t=500;
        cnt=0;
        memset(cap, 0, sizeof(cap));
        for(int i=0; i<n; i++){
            cin>>str;
            if(!conv[str]) conv[str]=++cnt;
            cap[conv[str]][t]++;
        }
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>str; cin>>str;
            if(!conv[str]) conv[str]=++cnt;
            cap[s][conv[str]]++;
        }
        cin>>k;
        for(int i=0; i<k; i++){//无限个转化器
            string s1, s2;
            cin>>s1>>s2;
            if(!conv[s1]) conv[s1]=++cnt;
            if(!conv[s2]) conv[s2]=++cnt;
            cap[conv[s1]][conv[s2]]=maxn;
        }
        cout<<m-EK()<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
