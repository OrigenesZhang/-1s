#include <iostream>
#include <cstring>
using namespace std;
int T, d[1005][1005];
string s;
bool vis[1005][1005];
void dp(int l, int r){
    if(vis[l][r]) return;
    vis[l][r]=true;
    if(l>=r){
        d[l][r]=0;
        return;
    }
    if(s.at(l)==s.at(r)){
        dp(l+1, r-1);
        d[l][r]=d[l+1][r-1];
    }else{
        dp(l+1, r-1);
        dp(l, r-1);
        dp(l+1, r);
        d[l][r]=min(min(d[l+1][r-1], d[l][r-1]), d[l+1][r])+1;
    }
}
int main(){
    cin>>T;
    cin.get();
    for(int cs=1; cs<=T; cs++){
        getline(cin, s);
        memset(vis, false, sizeof(vis));
        dp(0, s.length()-1);
        cout<<"Case "<<cs<<": "<<d[0][s.length()-1]<<endl;
    }
    return 0;
}
