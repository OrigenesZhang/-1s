//MST Prim Algorithm
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;
typedef pair<double, int> dis;
struct Point{
    double x, y;
    priority_queue<dis, vector<dis>, greater<dis> > d;
}p[105];
bool vis[105];
int n, T;
inline double dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
dis mmin(int k){
    while(!p[k].d.empty()){
        if(vis[p[k].d.top().second])
            p[k].d.pop();
        else return p[k].d.top();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>T;
    cout<<fixed<<setprecision(2);
    while(T--){
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>p[i].x>>p[i].y;
        memset(vis, false, sizeof(vis));
        double s=0;
        vis[1]=true;
        if(!p[1].d.empty()){
            priority_queue<dis, vector<dis>, greater<dis> > tmp;
            swap(p[1].d, tmp);
        }
        for(int i=2; i<=n; i++)
            p[1].d.push(make_pair(dist(p[1], p[i]), i));
        int cnt=1;
        while(cnt++<n){
            dis tmp;
            bool first=true;
            for(int i=1; i<=n; i++){
                if(!vis[i]) continue;
                if(first){
                    tmp=mmin(i);
                    first=false;
                }else{
                    tmp=min(tmp, mmin(i));
                }
            }
            vis[tmp.second]=true;
            if(!p[tmp.second].d.empty()){
                priority_queue<dis, vector<dis>, greater<dis> > t;
                swap(t, p[tmp.second].d);
            }
            for(int i=2; i<=n; i++){
                if(vis[i]) continue;
                p[tmp.second].d.push(make_pair(dist(p[tmp.second], p[i]), i));
            }
            s+=tmp.first;
        }
        cout<<s<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
