#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s[105], str[105];
bool vis[105];
int T, n;
int cmp(string s1, string s2){
    int len=min(s1.length(), s2.length());
    for(int i=0; i<len; i++)
        if(s2.at(i)!=s1.at(i)) return i;
    return len;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>s[i];
        memset(vis, 0, sizeof(vis));
        int cnt=s[0].length();
        str[0]=s[0];
        vis[0]=true;
        for(int i=1; i<n; i++){
            int cur, mmax=-1;
            for(int j=1; j<n; j++){
                if(vis[j]) continue;
                int tmp=cmp(str[i-1], s[j]);
                if(tmp>mmax){
                    mmax=tmp;
                    cur=j;
                }
            }
            str[i]=s[cur];
            vis[cur]=true;
            cnt+=str[i].length()-cmp(str[i-1], str[i]);
        }
        cout<<cnt<<endl;
        for(int i=0; i<n; i++)
            cout<<str[i]<<endl;
    }
    return 0;
}
