//二分图匹配
//添加源点和汇点+最大流
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
map<string, int> table;
int T, m, n, cap[50][50], flow[50][50], s, t, a[50], p[50];
string s1, s2;
const int maxn=0x7f7f7f7f;
int main(){
    table["XXL"]=1;
    table["XL"]=2;
    table["L"]=3;
    table["M"]=4;
    table["S"]=5;
    table["XS"]=6;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(cap, 0, sizeof(cap));
        s=0, t=10+m;
        cap[0][1]=cap[0][2]=cap[0][3]=cap[0][4]=cap[0][5]=cap[0][6]=n/6;
        for(int i=0; i<m; i++){
            cin>>s1>>s2;
            cap[table[s1]][i+10]=1;
            cap[table[s2]][i+10]=1;
            cap[i+10][t]=1;
        }
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
                for(int v=1; v<=t; v++){
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
        cout<<(f==m?"YES":"NO")<<endl;
    }
    return 0;
}
