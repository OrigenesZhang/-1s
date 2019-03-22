//这io是有毒吧
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
bool vis[25];
int N, A, B, cs=1;
vector<int> G[25];
typedef pair<int, int> pii;
queue<pii> q;
int main(){
    int cnt;
    while(cin>>cnt){
        cout<<"Test Set #"<<cs++<<endl;
        for(int i=1; i<=20; i++) G[i].clear();
        int J;
        while(cnt--){
            cin>>J;
            G[1].push_back(J);
            G[J].push_back(1);
        }
        for(int I=2; I<=19; I++){
            cin>>cnt;
            while(cnt--){
                cin>>J;
                G[I].push_back(J);
                G[J].push_back(I);
            }
        }
        cin>>N;
        while(N--){
            cin>>A>>B;
            memset(vis, false, sizeof(vis));
            if(!q.empty()){
                queue<pii> tmp;
                swap(tmp, q);
            }
            q.push(make_pair(A, 1));
            while(!q.empty()){
                int cur=q.front().first;
                int num=q.front().second;
                q.pop();
                vis[cur]=true;
                for(int i=0; i<G[cur].size(); i++){
                    if(vis[G[cur].at(i)]) continue;
                    if(G[cur].at(i)==B){
                        cout<<setw(2)<<A;
                        cout<<" to ";
                        cout<<setw(2)<<B;
                        cout<<": "<<num<<endl;
                        goto label;
                    }
                    q.push(make_pair(G[cur].at(i), num+1));
                }
            }
            label:;
        }
        cout<<endl;
    }
    return 0;
}
