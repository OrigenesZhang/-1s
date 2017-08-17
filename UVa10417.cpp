#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int t, n, g[5];
double res[5], table[15][5];
void dfs(int row, double p, int pos){
    if(row==n){
        res[pos]+=p;
        return;
    }
    for(int col=0; col<5; col++){
        if(g[col]&&table[row][col]){
            g[col]--;
            if(!row) pos=col;
            dfs(row+1, p*table[row][col], pos);
            g[col]++;
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>g[0]>>g[1]>>g[2]>>g[3]>>g[4];
        memset(res, 0, sizeof(res));
        for(int i=0; i<n; i++)
            for(int j=0; j<5; j++)
                cin>>table[i][j];
        dfs(0, 1, -1);
        double sum=0, mmax, num=0;
        for(int i=0; i<5; i++){
            if(g[i]){
                sum+=res[i];
                res[i]/=g[i];
            }
        }
        mmax=res[0];
        for(int i=1; i<5; i++){
            if(res[i]>mmax+1e-10){
                num=i;
                mmax=res[i];
            }
        }
        cout<<setprecision(0)<<num+1<<' ';
        cout<<fixed<<setprecision(3);
        cout<<mmax/sum<<endl;
    }
    return 0;
}
