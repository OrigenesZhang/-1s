#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=1<<18;
const int INF=0x7f7f7f7f;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
int N, n, m, S, T, First[maxn], u[maxn], v[maxn], w[maxn], d[maxn], Next[maxn];
bool vis[maxn];
void read_graph(){
    cin>>n>>m>>S>>T;
    for(int i=0; i<n; i++) First[i]=-1;
    m<<=1;
    for(int e=0; e<m; e+=2){//无向图的处理
        cin>>u[e]>>v[e]>>w[e];
        u[e+1]=v[e];
        v[e+1]=u[e];
        w[e+1]=w[e];
        Next[e]=First[u[e]];
        First[u[e]]=e;
        Next[e+1]=First[v[e]];
        First[v[e]]=e+1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int cs=1; cs<=N; cs++){
        cout<<"Case #"<<cs<<": ";
        read_graph();
        memset(d, 0x7f, sizeof(d));
        memset(vis, false, sizeof(vis));
        d[S]=0;
        if(!q.empty()){
            priority_queue<pii, vector<pii>, greater<pii> > tmp;
            swap(tmp, q);
        }
        q.push(make_pair(d[S], S));
        while(!q.empty()){
            pii cur=q.top();
            q.pop();
            if(vis[cur.second]) continue;
            vis[cur.second]=true;
            for(int e=First[cur.second]; e!=-1; e=Next[e]){
                if(d[v[e]]>d[cur.second]+w[e]){
                    d[v[e]]=d[cur.second]+w[e];
                    q.push(make_pair(d[v[e]], v[e]));
                }
            }
        }
        if(d[T]==INF) cout<<"unreachable"<<endl;
        else cout<<d[T]<<endl;
    }
    return 0;
}
