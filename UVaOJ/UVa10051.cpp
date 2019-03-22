#include <iostream>
#include <cstring>
using namespace std;
string s[6]={"front", "back", "left", "right", "top", "bottom"};
int table[505][6], N, dp[505][6], mmax, curc, curs, cs=1;
void print(){
    cout<<curc<<' '<<s[curs]<<endl;
    mmax--;
    int prev=curs&1?table[curc][curs-1]:table[curc][curs+1];
    for(int i=curc+1; i<=N; i++){
        for(int j=0; j<6; j++){
            if(dp[i][j]==mmax&&table[i][j]==prev){
                cout<<i<<' '<<s[j]<<endl;
                mmax--;
                prev=j&1?table[i][j-1]:table[i][j+1];
                break;
            }
        }
        if(!mmax) return;
    }
}
int main(){
    while(cin>>N){
        if(!N) break;
        for(int i=1; i<=N; i++)
            for(int j=0; j<6; j++)
                cin>>table[i][j];
        memset(dp, 0, sizeof(dp));
        mmax=0;
        for(int i=N; i>0; i--){
            for(int j=0; j<6; j++){
                dp[i][j]=1;
                for(int ii=N; ii>i; ii--){
                    for(int jj=0; jj<6; jj++){
                        if(j&1&&table[ii][jj]==table[i][j-1]) dp[i][j]=max(dp[ii][jj]+1, dp[i][j]);
                        else if(!(j&1)&&table[ii][jj]==table[i][j+1]) dp[i][j]=max(dp[ii][jj]+1, dp[i][j]);
                    }
                }
                if(dp[i][j]>mmax){
                    curc=i;
                    curs=j;
                    mmax=dp[i][j];
                }
            }
        }
        if(cs>1) cout<<endl;
        cout<<"Case #"<<cs++<<endl;
        cout<<mmax<<endl;
        print();
    }
    return 0;
}
