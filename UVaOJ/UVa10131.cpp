#include <iostream>
#include <algorithm>
using namespace std;
struct elephant{
    int index, weight, IQ;
    bool operator < (const elephant& b) const{
        if(weight!=b.weight) return weight<b.weight;
        return IQ>b.IQ;
    }
}e[1000];
int dp[1000], path[1000];
int main(){
    int n=0, tmpw, tmpi;
    while(cin>>tmpw>>tmpi){
        elephant tmp={n+1, tmpw, tmpi};
        e[n++]=tmp;
    }
    sort(e, e+n);
    int tot=0, cur;
    for(int i=n-1; i>=0; i--){
        dp[i]=1;
        path[i]=-1;
        for(int j=i+1; j<n; j++){
            if(e[i].weight<e[j].weight&&e[i].IQ>e[j].IQ&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                path[i]=j;
            }
        }
        if(dp[i]>tot){
            tot=dp[i];
            cur=i;
        }
    }
    cout<<tot<<endl;
    for(int i=cur; i!=-1; i=path[i])
        cout<<e[i].index<<endl;
    return 0;
}
