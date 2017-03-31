#include <iostream>
#include <cstring>
using namespace std;
string s1, s2;
long long s[50][50], dp[50][50];
int T, len1, len2;
int main(){
    cin>>T;
    cin.get();
    for(int cs=1; cs<=T; cs++){
        getline(cin, s1);
        getline(cin, s2);
        len1=s1.length();
        len2=s2.length();
        memset(s, 0, sizeof(s));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=len1; i++)
            dp[i][0]=1;
        for(int i=0; i<=len2; i++)
            dp[0][i]=1;
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(s1.at(i-1)==s2.at(j-1)){
                    s[i][j]=s[i-1][j-1]+1;
                    dp[i][j]=dp[i-1][j-1];
                }else if(s[i-1][j]>s[i][j-1]){
                    s[i][j]=s[i-1][j];
                    dp[i][j]=dp[i-1][j];
                }else if(s[i][j-1]>s[i-1][j]){
                    s[i][j]=s[i][j-1];
                    dp[i][j]=dp[i][j-1];
                }else{
                    s[i][j]=s[i-1][j];
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        cout<<"Case #"<<cs<<": "<<len1+len2-s[len1][len2]<<' '<<dp[len1][len2]<<endl;
    }
    return 0;
}
