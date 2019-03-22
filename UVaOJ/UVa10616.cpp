#include <iostream>
#include <cstring>
using namespace std;
long long dp[15][45];
int num[205], N, Q, cnt=1;
int main(){
    while(cin>>N>>Q){
        if(!N) break;
        cout<<"SET "<<cnt++<<':'<<endl;
        for(int i=0; i<N; i++) cin>>num[i];
        for(int cs=1; cs<=Q; cs++){
            int D, M, n[205];
            cin>>D>>M;
            for(int i=0; i<N; i++)
                n[i]=num[i]%D;
            memset(dp, 0, sizeof(dp));
            dp[0][0]=1;
            for(int i=0; i<N; i++)
                for(int j=M; j>0; j--)
                    for(int k=0; k<D; k++)
                        dp[j][k]+=dp[j-1][(k-n[i]+D)%D];
            cout<<"QUERY "<<cs<<": "<<dp[M][0]<<endl;
        }
    }
    return 0;
}
//01背包
