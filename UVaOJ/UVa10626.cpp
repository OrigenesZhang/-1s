#include <iostream>
#include <cstring>
using namespace std;
bool vis[1200][240][55];
int d[1200][240][55], C, n1, n5, n10, T;
int dp(int coke, int x, int y, int z){
    if(vis[x][y][z]) return d[x][y][z];
    vis[x][y][z]=true;
    if(!coke) return d[x][y][z]=0;
    if(x>=8) d[x][y][z]=min(d[x][y][z], dp(coke-1, x-8, y, z)+8);
    if(y>=1&&x>=3) d[x][y][z]=min(d[x][y][z], dp(coke-1, x-3, y-1, z)+4);
    if(y>=2) d[x][y][z]=min(d[x][y][z], dp(coke-1, x+2, y-2, z)+2);
    if(z>=1) d[x][y][z]=min(d[x][y][z], dp(coke-1, x+2, y, z-1)+1);
    if(z>=1&&x>=3) d[x][y][z]=min(d[x][y][z], dp(coke-1, x-3, y+1, z-1)+4);//非常重要,这种情况事实上优于上一种因为只找回一枚硬币
    return d[x][y][z];
}
int main(){
    cin>>T;
    while(T--){
        cin>>C>>n1>>n5>>n10;
        memset(vis, false, sizeof(vis));
        memset(d, 0x3f, sizeof(d));
        cout<<dp(C, n1, n5, n10)<<endl;
    }
    return 0;
}
