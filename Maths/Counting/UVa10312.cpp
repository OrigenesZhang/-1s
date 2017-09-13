#include <iostream>
#include <cstring>
using namespace std;
long long catalan[30], d[30][2];
int N;
long long dp(int n, int lft){
    long long& res=d[n][lft];
    if(res!=-1) return res;
    if(n<=1) return res=1;
    res=0;
    for(int i=1; i<n+lft; i++)
        res+=dp(i, 1)*dp(n-i, 0);
    return res;
}
int main(){
    catalan[1]=1;
    for(int i=2; i<=26; i++)
        catalan[i]=(4*i-6)*catalan[i-1]/i;
    memset(d, -1, sizeof(d));
    while(cin>>N)
        cout<<dp(N, 0)-catalan[N]<<endl;
    return 0;
}
/*
这个题目的总字串数貌似是一个叫super catalan number的东西;
满足:
s[n]=(3*(2*n-3)*s[n-1]-(n-3)*s[n-2])/n;
s[1]=s[2]=1;
*/
