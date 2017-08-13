//这题uDebug里面有些输出是错的[把有解误判成无解]
#include <iostream>
#include <cstring>
using namespace std;
int T, n, table[30], pos;
string s;
long long permutation(int p){
    long long res=1;
    for(int i=2; i<=p; i++) res*=i;
    return res;
}
long long cal(int tot){
    long long res=1;
    while(tot) res*=tot--;
    for(int i=1; i<=26; i++)
        if(table[i]) res/=permutation(table[i]);
    return res;
}
void dfs(int tot, long long cur){
    if(!tot){
        if(cur>1) cout<<"XXX";
        else if(pos) cout<<(char)(pos+'a'-1);
        return;
    }
    long long res;
    for(int i=1; i<=26; i++){
        if(table[i]){
            table[i]--;
            res=cal(tot-1);
            if(res<cur) cur-=res;
            else{
                cout<<(char)(i+'a'-1);
                dfs(tot-1, cur);
                cout<<(char)(i+'a'-1);
                return;
            }
            table[i]++;
        }
    }
    cout<<"XXX";
}
int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        cout<<"Case "<<t<<": ";
        cin>>s>>n;
        memset(table, 0, sizeof(table));
        pos=0;
        int cnt=0;
        for(int i=0; i<s.length(); i++) table[s.at(i)-'a'+1]++;
        for(int i=1; i<=26; i++){
            if(table[i]&1){
                pos=i;
                cnt++;
            }
        }
        if(cnt>1){
            cout<<"XXX"<<endl;
            continue;
        }
        int tot=0;
        for(int i=1; i<=26; i++){
            table[i]>>=1;
            tot+=table[i];
        }
        dfs(tot, n);
        cout<<endl;
    }
    return 0;
}
