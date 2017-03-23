#include <iostream>
#include <cstring>
using namespace std;
string s;
int T, dp[1050][1050];
int main(){
    cin>>T;
    cin.get();
    while(T--){
        getline(cin, s);//如果题目没有说默认有空行可以少WA一次
        int len=s.length();
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<len; i++)
            dp[i][i]=1;
        for(int i=len-1; i>=0; i--){
            for(int j=i+1; j<len; j++){
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                if(s.at(i)==s.at(j)) dp[i][j]=max(dp[i][j], dp[i+1][j-1]+2);
            }
        }
        cout<<dp[0][len-1]<<endl;
    }
    return 0;
}
