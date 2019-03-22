#include <iostream>
#include <sstream>
using namespace std;
const int maxn=2147483647;
int N;
long long dp[205][205];
string s;
long long local_max(int st, int len){
    string str=s.substr(st, len+1);
    istringstream i(str);
    long long res;
    i>>res;
    if(res>maxn) return -1;
    return res;
}
int main(){
    cin>>N;
    while(N--){
        cin>>s;
        int len=s.length();
        if(len<10){
            long long res;
            istringstream i(s);//string输入到long long再输出消去leading 0
            i>>res;
            cout<<res<<endl;
            continue;
        }
        for(int i=0; i<len; i++)
            dp[i][i]=s.at(i)-'0';
        for(int i=1; i<len; i++){
            for(int j=0; i+j<len; j++){
                long long cur=-1;
                if(i<10) cur=local_max(j, i);
                for(int k=0; k<i; k++)
                    cur=max(cur, dp[j][j+k]+dp[j+k+1][i+j]);
                dp[j][i+j]=cur;
            }
        }
        cout<<dp[0][len-1]<<endl;
    }
    return 0;
}
