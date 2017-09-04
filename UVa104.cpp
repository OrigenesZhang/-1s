#include <iostream>
#include <cstring>
using namespace std;
int path[25][25][25], n;
double d[25][25][25];
void print(int i, int j, int u){
    if(!u){
        cout<<i+1;
        return;
    }
    print(i, path[i][j][u]-1, u-1);
    cout<<' '<<path[i][j][u];
}
int main(){
    while(cin>>n){
        memset(d, 0, sizeof(d));
        memset(path, 0, sizeof(path));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    d[i][j][0]=1;
                    continue;
                }
                cin>>d[i][j][0];
            }
        }
        for(int u=1; u<=n; u++){
            for(int k=0; k<n; k++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(d[i][j][u]<d[i][k][u-1]*d[k][j][0]){
                            d[i][j][u]=d[i][k][u-1]*d[k][j][0];
                            path[i][j][u]=k+1;
                        }
                    }
                }
            }
            for(int i=0; i<n; i++){
                if(d[i][i][u]>1.01){
                    print(i, i, u);
                    cout<<' '<<i+1<<endl;
                    goto label;
                }
            }
        }
        cout<<"no arbitrage sequence exists"<<endl;
        label:;
    }
    return 0;
}
