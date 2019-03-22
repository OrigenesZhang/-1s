#include <iostream>
#include <cstring>
using namespace std;
string s;
int T, dist, dp[105][205], d[105], p[105];
int main(){
    cin>>T;
    while(T--){
        cin>>dist;
        cin.get();
        int N=0, prev=0;
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        while(getline(cin, s)){//输入真恶心
            if(s=="") break;
            bool flag=true;
            N++;
            for(int i=0; i<s.length(); i++){
                if(s.at(i)==' '){
                    flag=false;
                    continue;
                }
                if(flag) d[N]*=10, d[N]+=s.at(i)-'0';
                else p[N]*=10, p[N]+=s.at(i)-'0';
            }
            int tmp;
            tmp=d[N], d[N]-=prev, prev=tmp;
        }
        d[N+1]=dist-prev;
        if(d[N+1]>100){
            cout<<"Impossible"<<endl;
            if(T) cout<<endl;
            continue;
        }
        memset(dp, -1, sizeof(dp));
        dp[0][100]=0;
        for(int i=1; i<=N; i++){
            for(int j=d[i]; j<=200; j++){
                if(dp[i-1][j]<0) continue;
                for(int k=max(d[i+1]+d[i]-j, 0); k<=200-j+d[i]; k++)
                    if(dp[i][j-d[i]+k]<0) dp[i][j-d[i]+k]=dp[i-1][j]+k*p[i];
                    else dp[i][j-d[i]+k]=min(dp[i][j-d[i]+k], dp[i-1][j]+k*p[i]);
            }
        }
        if(dp[N][100+d[N+1]]<0) cout<<"Impossible"<<endl;
        else cout<<dp[N][100+d[N+1]]<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
