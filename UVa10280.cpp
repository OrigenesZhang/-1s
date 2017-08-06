#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int maxsize[110], minsize[110], dp[450010], record[4510];
bool vis[4510];
int main(){
    int cs;
    cin>>cs;
    while(cs--){
        int w, s, cur;
        cin>>w>>s;
        w*=1000;
        int lowerlmt=0x3f3f3f3f;
        for(int i=0; i<s; i++){
            cin>>minsize[i]>>maxsize[i];
            lowerlmt=min(lowerlmt, minsize[i]*maxsize[i]/(maxsize[i]-minsize[i]));
        }
        if(lowerlmt<=w){
            cout<<0<<endl;
            goto label;
        }
        memset(vis, false, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        cur=0;//goto statement cannot jump across any definition statements
        for(int i=0; i<s; i++){
            for(int j=minsize[i]; j<=maxsize[i]; j++){
                if(!vis[j]){
                    record[cur++]=j;
                    vis[j]=true;
                }
            }
        }
        dp[0]=1;
        for(int i=0; i<cur; i++)
            for(int j=record[i]; j<=w; j++)
                if(dp[j-record[i]]==1) dp[j]=1;
        for(int i=w; i>=0; i--){
            if(dp[i]){
                cout<<w-i<<endl;
                break;
            }
        }
        label:
        if(cs) cout<<endl;
    }
    return 0;
}
