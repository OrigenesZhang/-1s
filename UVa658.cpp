#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int product=1, n, m, dist[1<<21], cost[105];
string p[105][2];
typedef pair<int, int> pii;
bool vis[1<<21];
priority_queue<pii, vector<pii>, greater<pii> > q;
int main(){
    ios_base::sync_with_stdio(false);
    while(cin>>n>>m){
        if(!n) break;
        cout<<"Product "<<product++<<endl;
        for(int i=1; i<=m; i++)
            cin>>cost[i]>>p[i][0]>>p[i][1];
        memset(dist, 0x3f, sizeof(dist));
        memset(vis, false, sizeof(vis));
        dist[(1<<n)-1]=0;
        if(!q.empty()){
            priority_queue<pii, vector<pii>, greater<pii> > tmp;
            swap(q, tmp);
        }
        q.push(make_pair(0, (1<<n)-1));
        while(!q.empty()){
            pii cur=q.top();
            q.pop();
            if(!cur.second){
                cout<<"Fastest sequence takes "<<cur.first<<" seconds."<<endl;
                goto label;
            }
            if(vis[cur.second]) continue;
            vis[cur.second]=true;
            for(int i=1; i<=m; i++){
                bool flag=true;
                for(int j=0; j<n; j++){
                    if(p[i][0].at(j)=='+'&&!(cur.second&(1<<j))){
                        flag=false;
                        break;
                    }
                    if(p[i][0].at(j)=='-'&&(cur.second&(1<<j))){
                        flag=false;
                        break;
                    }
                }
                if(!flag) continue;
                pii curr=cur;
                for(int j=0; j<n; j++){
                    if(p[i][1].at(j)=='+') curr.second|=(1<<j);
                    else if(p[i][1].at(j)=='-') curr.second&=(~(1<<j));
                }
                if(curr.first+cost[i]<dist[curr.second]){
                    dist[curr.second]=curr.first+cost[i];
                    q.push(make_pair(curr.first+cost[i], curr.second));
                }
            }
        }
        cout<<"Bugs cannot be fixed."<<endl;
        label:
        cout<<endl;
    }
    return 0;
}
