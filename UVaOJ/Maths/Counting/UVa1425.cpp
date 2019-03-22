#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<double, double> pii;
int dp[60][60], T, n, res;
pii pts[60];
inline double xproduct(pii v1, pii v2, pii u1, pii u2){
    pii v=make_pair(v2.first-v1.first, v2.second-v1.second);
    pii u=make_pair(u2.first-u1.first, u2.second-u1.second);
    return v.first*u.second-u.first*v.second;
}
bool judge(int s, int t, int flag){
    for(int i=s+1; i<t; i++)
        if(xproduct(pts[s], pts[i], pts[s], pts[t])*flag<=0) return false;
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>pts[i].first>>pts[i].second;
        sort(pts, pts+n);
        memset(dp, 0, sizeof(dp));
        dp[0][1]=dp[1][0]=1;
        for(int i=2; i<n; i++){
            for(int j=0; j<i-1; j++){
                dp[i][j]+=dp[i-1][j];
                dp[j][i]+=dp[j][i-1];
            }
            for(int j=0; j<i-1; j++){
                if(judge(j, i, 1))
                    dp[i][i-1]+=dp[j][i-1];
                if(judge(j, i, -1))
                    dp[i-1][i]+=dp[i-1][j];
            }
        }
        res=0;
        for(int i=0; i<n-1; i++){
            if(judge(i, n-1, 1))
                res+=dp[i][n-1];
            if(judge(i, n-1, -1))
                res+=dp[n-1][i];
        }
        cout<<res/2<<endl;
    }
    return 0;
}
