//Dijkstra
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;
int d[105], w[105][105], n, k, t[6];
const int maxn=0x3f3f3f3f;
bool vis[105];
string s;
int main(){
    while(cin>>n>>k){
        for(int i=1; i<=n; i++) cin>>t[i];
        memset(vis, false, sizeof(vis));
        memset(w, 0x3f, sizeof(w));
        memset(d, 0x3f, sizeof(d));
        cin.get();
        for(int i=1; i<=n; i++){
            getline(cin, s);
            stringstream ss(s);
            int cur;
            vector<int> v;
            while(ss>>cur){
                for(int j=0; j<v.size(); j++){
                    w[v[j]][cur]=min(w[v[j]][cur], (cur-v[j])*t[i]);
                    w[cur][v[j]]=min(w[v[j]][cur], (cur-v[j])*t[i]);
                }
                v.push_back(cur);
            }
        }
        if(!k){//到0楼还坐电梯怕不是有毛病
            cout<<0<<endl;
            continue;
        }
        d[0]=0;
        for(int i=0; i<100; i++){
            int x, m=maxn;
            for(int y=0; y<100; y++)
                if(!vis[y]&&d[y]<=m)
                    m=d[x=y];
            vis[x]=true;
            for(int y=0; y<100; y++)
                d[y]=min(d[y], d[x]+w[x][y]+60);
        }
        if(d[k]==maxn) cout<<"IMPOSSIBLE"<<endl;
        else cout<<d[k]-60<<endl;
    }
    return 0;
}
