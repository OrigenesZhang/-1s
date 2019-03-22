#include <iostream>
using namespace std;
string s[25050], cur;
int dp[25050], N=0, mmax=0;
int b_search(int r, string str){
    int l=1, m=0;
    while(l<=r){
        m=(l+r)>>1;
        if(s[m]==str) return m;
        if(s[m]>str) r=m-1;
        else l=m+1;
    }
    return 0;
}
int main(){
    while(cin>>s[++N]);
    for(int i=1; i<=N; i++){
        dp[i]=1;
        int len=s[i].length();
        for(int j=0; j<len; j++){
            cur=s[i];
            cur.erase(j, 1);
            int pos=b_search(i-1, cur);
            if(pos) dp[i]=max(dp[i], dp[pos]+1);
        }
        for(int j=0; j<=len; j++){
            for(char ch='a'; ch<='z'; ch++){
                cur=s[i];
                cur.insert(j, 1, ch);
                int pos=b_search(i-1, cur);
                if(pos) dp[i]=max(dp[i], dp[pos]+1);
            }
        }
        for(int j=0; j<len; j++){
            for(char ch='a'; ch<='z'; ch++){
                cur=s[i];
                if(cur.at(j)==ch) continue;
                cur.at(j)=ch;
                int pos=b_search(i-1, cur);
                if(pos) dp[i]=max(dp[i], dp[pos]+1);
            }
        }
        mmax=max(dp[i], mmax);
    }
    cout<<mmax<<endl;
    return 0;
}
