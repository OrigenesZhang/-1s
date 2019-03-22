#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
double p[25], res[25];
int n, r, cs=1;
double dfs(int cur, int left, double probability){
    if(cur>n) return left?0:probability;
    double tot=0;
    if(left){
        tot+=dfs(cur+1, left-1, probability*p[cur]);
        res[cur]+=tot;
    }
    tot+=dfs(cur+1, left, probability*(1-p[cur]));
    return tot;
}
int main(){
    while(cin>>n>>r){
        if(!n&&!r) break;
        cout<<"Case "<<cs++<<':'<<endl;
        for(int i=1; i<=n; i++) cin>>p[i];
        memset(res, 0, sizeof(res));
        double q=dfs(1, r, 1);
        cout<<fixed<<setprecision(6);
        for(int i=1; i<=n; i++)
            cout<<res[i]/q<<endl;
    }
    return 0;
}
