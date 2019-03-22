#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=0x7f7f7f7f;
int n, m, si, ni, ki;
int d[105], u[205], v[205], w[205], First[205], Next[205], cnt[205], edgenum;
bool vis[105], inq[105];
string oi;
queue<int> q;
void read_graph(){//差分约束图
    edgenum=0;
    memset(First, -1, sizeof(First));
    memset(vis, false, sizeof(vis));
    for(int e=0; e<m; e++){
        cin>>si>>ni>>oi>>ki;
        ni+=si;
        si--;
        vis[ni]=vis[si]=true;
        if(oi=="lt"){
            u[edgenum]=si;
            v[edgenum]=ni;
            w[edgenum]=--ki;
            Next[edgenum]=First[si];
            First[si]=edgenum++;
        }else{
            u[edgenum]=ni;
            v[edgenum]=si;
            w[edgenum]=-(++ki);
            Next[edgenum]=First[ni];
            First[ni]=edgenum++;
        }
    }
    vis[n+1]=true;
    for(int i=0; i<=n; i++){
        if(vis[i]){
            u[edgenum]=n+1;
            v[edgenum]=i;
            w[edgenum]=0;
            Next[edgenum]=First[n+1];
            First[n+1]=edgenum++;
        }
    }
}
int main(){
    while(cin>>n){
        if(!n) break;
        cin>>m;
        read_graph();
        memset(d, 0x7f, sizeof(d));
        d[n+1]=0;
        memset(cnt, 0, sizeof(cnt));
        cnt[n+1]=1;
        memset(inq, false, sizeof(inq));
        if(!q.empty()){
            queue<int> tmp;
            swap(tmp, q);
        }
        q.push(n+1);
        while(!q.empty()){//spfa
            int x=q.front();
            q.pop();
            inq[x]=false;
            for(int e=First[x]; e!=-1; e=Next[e]){
                if(d[v[e]]>d[x]+w[e]){
                    d[v[e]]=d[x]+w[e];
                    if(!inq[v[e]]){
                        inq[v[e]]=true;
                        q.push(v[e]);
                        if(++cnt[v[e]]>n+1){
                            cout<<"successful conspiracy"<<endl;
                            goto label;
                        }
                    }
                }
            }
        }
        cout<<"lamentable kingdom"<<endl;
        label:;
    }
    return 0;
}
