#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1[105], s2[105];
int dp[105][105]={0}, path[105][105];
int main(){
    while(1){
        int cnt1=1, cnt2=1;
        while(cin>>s1[cnt1]&&s1[cnt1]!="#") cnt1++;
        while(cin>>s2[cnt2]&&s2[cnt2]!="#") cnt2++;
        if(cnt1==1) break;
        for(int i=1; i<cnt1; i++){
            for(int j=1; j<cnt2; j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    path[i][j]=0;
                }else{
                    if(dp[i-1][j]>dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        path[i][j]=1;
                    }else{
                        dp[i][j]=dp[i][j-1];
                        path[i][j]=2;
                    }
                }
            }
        }
        vector<string> ans;
        int i=cnt1-1, j=cnt2-1;
        while(i&&j){
            if(!path[i][j]){
                ans.push_back(s1[i]);
                i--;
                j--;
            }else if(path[i][j]==1) i--;
            else j--;
        }
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i];
            if(i) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
