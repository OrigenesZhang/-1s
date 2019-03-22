#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn=1<<30;
int S, M, N, tot, init, dp[1<<8][1<<8], shift[125], cost[125], cnt[10];
string s;
int main(){
    while(cin>>S>>M>>N){
        if(!S) break;
        init=(1<<S)-1;
        tot=0;
        int st1=0, st2=0;
        memset(cnt, 0, sizeof(cnt));
        for(int i=1; i<=M+N; i++){
            cin>>cost[i];
            getline(cin, s);
            shift[i]=0;
            for(int j=0; j<s.length(); j++){
                if(isdigit(s.at(j))){
                    int num=s.at(j)-'0';
                    shift[i]|=1<<(num-1);
                    if(i<=M) cnt[num-1]++;
                }
            }
            if(i<=M){
                tot+=cost[i];
                st1|=shift[i];
            }
        }
        for(int i=0; i<S; i++) if(cnt[i]>1) st2|=(1<<i);
        memset(dp, 0x3f, sizeof(dp));
        dp[st1][st2]=tot;
        for(int i=M+1; i<=M+N; i++){
            for(int j=init; j>=0; j--){
                for(int k=init; k>=0; k--){
                    if(dp[j][k]>maxn) continue;
                    st1=shift[i]|j;
                    st2=(shift[i]&j)|k;
                    dp[st1][st2]=min(dp[st1][st2], dp[j][k]+cost[i]);
                }
            }
        }
        cout<<dp[init][init]<<endl;
    }
    return 0;
}
