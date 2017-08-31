#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
struct Point{
    int x, y;
}p[550];
const int maxn=550*550;
int N, S, P[550], u[maxn], v[maxn], w[maxn], r[maxn], T;
inline bool cmp(const int i, const int j){
    return w[i]<w[j];
}
int Find(int x){
    return P[x]==x?x:P[x]=Find(P[x]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>T;
    cout<<fixed<<setprecision(2);
    while(T--){
        cin>>S>>N;
        for(int i=1; i<=N; i++)
            cin>>p[i].x>>p[i].y;
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
        double ans=0;
        for(int i=1; i<=N; i++) P[i]=i;
        sort(r+1, r+m+1, cmp);
        int cnt=0;
        for(int i=1; i<=m; i++){
            int e=r[i];
            int x=Find(u[e]);
            int y=Find(v[e]);
            if(x!=y){
                ans=sqrt(w[e]);
                P[x]=y;
                if(++cnt>=N-S) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
