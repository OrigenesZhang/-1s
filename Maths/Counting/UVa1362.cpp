#include <iostream>
#include <cstring>
using namespace std;
const int MOD=1000000000;
long long d[310][310];
string s;
long long dp(int i, int j){
    if(i==j) return d[i][j]=1;
    if(s.at(i)!=s.at(j)) return d[i][j]=0;
    if(d[i][j]!=-1) return d[i][j];
    long long& res=d[i][j];
    res=0;
    for(int k=i+2; k<=j; k++)
        if(s.at(i)==s.at(k))
            res=(res+dp(i+1, k-1)*dp(k, j))%MOD;
    return res;
}
int main(){
    while(cin>>s){
        int len=s.length()-1;
        memset(d, -1, sizeof(d));
        cout<<dp(0, len)<<endl;
    }
    return 0;
}
