//Bellman-Ford Algorithm
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=0x7f7f7f7f;
int d[1050], w[2050], u[2050], v[2050], c, n, m;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>c;
    while(c--){
        cin>>n>>m;
        memset(d, 0x7f, sizeof(d));
        for(int i=0; i<m; i++)
            cin>>u[i]>>v[i]>>w[i];
        d[0]=0;
        for(int k=0; k<n-1; k++){
            for(int i=0; i<m; i++){
                int x=u[i], y=v[i];
                if(d[x]<maxn) d[y]=min(d[x]+w[i], d[y]);
            }
        }
        for(int i=0; i<m; i++){
            int x=u[i], y=v[i];
            if(d[x]+w[i]<d[y]){
                cout<<"possible"<<endl;
                goto label;
            }
        }
        cout<<"not possible"<<endl;
        label:;
    }
    return 0;
}
