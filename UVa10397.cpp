//MST Kruskal Algorithm
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
struct Point{
    int x, y;
}p[800];
const int maxn=800*800;
int N, M, P[800], u[maxn], v[maxn], w[maxn], r[maxn];
inline bool cmp(const int i, const int j){
    return w[i]<w[j];
}
int Find(int x){
    return P[x]==x?x:P[x]=Find(P[x]);
}
int main(){
    cout<<fixed<<setprecision(2);
    while(cin>>N){
        for(int i=1; i<=N; i++)
            cin>>p[i].x>>p[i].y;
        cin>>M;
        int m=1;
        for(int i=1; i<=N-1; i++){
            for(int j=i+1; j<=N; j++){
                w[m]=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
                u[m]=i;
                v[m]=j;
                r[m]=m;
                m++;
            }
        }
        m--;
        for(int i=1; i<=M; i++){
            int uu, vv;
            cin>>uu>>vv;
            if(uu>vv) swap(uu, vv);
            w[(2*N-uu)*(uu-1)/2+vv-uu]=0;
        }
        double ans=0;
        for(int i=1; i<=N; i++) P[i]=i;
        sort(r+1, r+m+1, cmp);
        for(int i=1; i<=m; i++){
            int e=r[i];
            int x=Find(u[e]);
            int y=Find(v[e]);
            if(x!=y){
                ans+=sqrt(w[e]);
                P[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
