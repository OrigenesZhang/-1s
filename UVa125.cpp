#include <iostream>
#include <cstring>
using namespace std;
int n, m, u, v, d[40][40], city=0;
int main(){
    while(cin>>m){
        n=0;
        memset(d, 0, sizeof(d));
        for(int i=0; i<m; i++){
            cin>>u>>v;
            d[u][v]=1;
            n=max(n, u);
            n=max(n, v);
        }
        n++;
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    d[i][j]+=d[i][k]*d[k][j];
        for(int k=0; k<n; k++)
            if(d[k][k])
                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        if(d[i][k]&&d[k][j])
                            d[i][j]=-1;
        cout<<"matrix for city "<<city++<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j) cout<<' ';
                cout<<d[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
