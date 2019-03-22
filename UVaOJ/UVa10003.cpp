#include <iostream>
#include <cstring>
using namespace std;
int a[55], c[55][55], l, n;
bool vis[55][55];
void dp(int i, int j){
    if(vis[i][j]) return;
    vis[i][j]=true;
    dp(i+1, j);
    int mmin=c[i+1][j];
    for(int k=i+2; k<j; k++){
        dp(i, k);
        dp(k, j);
        if(c[i][k]+c[k][j]<mmin) mmin=c[i][k]+c[k][j];
    }
    c[i][j]=mmin+a[j]-a[i];
}
int main(){
    while(cin>>l){
        if(!l) break;
        cin>>n;
        a[0]=0, a[n+1]=l;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        memset(vis, false, sizeof(vis));
        for(int i=0; i<=n; i++)
            c[i][i+1]=0, vis[i][i+1]=true;
        dp(0, n+1);
        cout<<"The minimum cutting is "<<c[0][n+1]<<'.'<<endl;//句号没有WA了一次
    }
    return 0;
}
