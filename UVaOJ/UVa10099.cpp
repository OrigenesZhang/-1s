#include <iostream>
#include <algorithm>
using namespace std;
int N, R, S, T, D, cs=1, p[105], r[10050], w[10050], u[10050], v[10050];
inline bool cmp(const int i, const int j){
    return w[i]>w[j];
}
int Find(int x){
    return p[x]==x?x:p[x]=Find(p[x]);
}
int main(){
    while(cin>>N>>R){
        if(!N&&!R) break;
        for(int i=1; i<=R; i++){
            int U, V, P;
            cin>>U>>V>>P;
            u[i]=U;
            v[i]=V;
            w[i]=P-1;
            r[i]=i;
        }
        cin>>S>>T>>D;
        cout<<"Scenario #"<<cs++<<endl;
        if(S==T){
            cout<<"Minimum Number of Trips = "<<0<<'\n'<<endl;
            continue;
        }
        for(int i=1; i<=N; i++) p[i]=i;
        sort(r+1, r+R+1, cmp);
        for(int i=1; i<=R; i++){
            int e=r[i];
            int x=Find(u[e]);
            int y=Find(v[e]);
            if(x!=y){
                p[x]=y;
                if(Find(S)==Find(T)){
                    cout<<"Minimum Number of Trips = "<<D/w[e]+(D%w[e]>0)<<'\n'<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
