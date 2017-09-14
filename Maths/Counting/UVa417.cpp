#include <iostream>
#include <map>
using namespace std;
map<string, int> mmap;
int cnt=1;
void construct(string s, char prev, int pos, int len){
    if(pos==len){
        mmap[s]=cnt++;
        return;
    }
    bool first=true;
    for(char cur=prev+1; cur<='z'-len+pos+1; cur++){
        if(first){
            s+=cur;
            first=false;
        }else s.at(pos)=cur;
        construct(s, cur, pos+1, len);
    }
}
int main(){
    for(int len=1; len<=5; len++){
        string s;
        char prev='a'-1;
        construct(s, prev, 0, len);
    }
    string s;
    while(cin>>s) cout<<mmap[s]<<endl;
    return 0;
}
