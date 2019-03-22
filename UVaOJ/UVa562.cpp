#include <iostream>
#include <cstring>
using namespace std;
bool vis[25010];
int coins[110], m, upp, sum, n;
int main(){
    cin>>n;
    while(n--){
        cin>>m;
        sum=0;
        for(int i=1; i<=m; i++){
            cin>>coins[i];
            sum+=coins[i];
        }
        upp=sum/2;
        memset(vis, false, sizeof(vis));
        vis[0]=true;
        for(int i=1; i<=m; i++)
            for(int j=upp; j>=1; j--)
                if(!vis[j])
                    vis[j]=(j>=coins[i])?vis[j-coins[i]]:false;
        for(int i=upp; i>=0; i--){
            if(vis[i]){
                cout<<sum-i*2<<endl;
                break;
            }
        }
    }
    return 0;
}
