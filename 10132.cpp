#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
string frag[200];
int p, len;
bool vis[200];
set<string> v;
bool judge(string str){
    for(int i=0; i<p; i++){
        for(int j=p-1; j>i; j--){
            if(!vis[i]&&!vis[j]&&(frag[i]+frag[j]==str||frag[j]+frag[i]==str))
                vis[i]=vis[j]=1;
        }
        if(!vis[i]) return false;
    }
    if(!v.count(str)){
        v.insert(str);
        cout<<str<<endl;
    }
    return true;
}
void solve(){
    v.clear();
    memset(vis, 0, sizeof(vis));
    string tmp;
    len=frag[0].length()+frag[p-1].length();
    for(int i=0; i<p; i++){
        for(int j=p-1; j>i; j--){
            int tlen=frag[i].length()+frag[j].length();
            if(tlen<len) break;
            vis[i]=1;
            vis[j]=1;
            judge(frag[i]+frag[j]);
            memset(vis, 0, sizeof(vis));
            judge(frag[j]+frag[i]);
            memset(vis, 0, sizeof(vis));
        }
    }
}
inline bool cmp(string a, string b){
    return a.length()<b.length();
}
int main(){
    int tst;
    cin>>tst;
    cin.ignore();
    string tmp;
    getline(cin,tmp);
    while(tst--){
        p=0;
        while(getline(cin,tmp)){
            if(!tmp.empty()) frag[p++]=tmp;
            else break;
        }
        sort(frag, frag+p, cmp);
        solve();
        if(tst) cout<<endl;
    }
    return 0;
}
