#include <iostream>
#include <string>
using namespace std;
int T;
string s;
bool dp(int l, int r){
    if(l==r) return s.at(l)=='A';
    if(s.at(l)=='B'&&s.at(r)=='A') return dp(l+1, r-1);
    if(s.at(r-1)=='A'&&s.at(r)=='B') return dp(l, r-2);
    return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        if(s=="A"){
            cout<<"SIMPLE"<<endl;
            continue;
        }
        int len=s.length();
        if(!(len&1)){
            cout<<"MUTANT"<<endl;
            continue;
        }
        if(s.at(len-2)=='A'&&s.at(len-1)=='B'&&dp(0, len-3)){
            cout<<"FULLY-GROWN"<<endl;
            continue;
        }
        if(s.at(0)=='B'&&s.at(len-1)=='A'&&dp(1, len-2)){
            cout<<"MUTAGENIC"<<endl;
            continue;
        }
        cout<<"MUTANT"<<endl;
    }
    return 0;
}
