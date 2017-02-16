#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<char> s;
bool alphabet[26];
int T;
int main(){
    cin>>T;
    cin.get();
    while(T--){
        s.clear();
        memset(alphabet, false, sizeof(alphabet));
        string tmp;
        cin>>tmp;
        int cur=0;
        while(cur<tmp.length()){
            s.push_back(tmp.at(cur));
            alphabet[tmp.at(cur++)-'a']^=1;
        }//我也不知道为什么要这么写但是不这么写就会T会给输入搞lol
        int sz=s.size(), tot=0;
        if(sz&1){
            int cnt=0;
            for(int i=0; i<26; i++)
                if(alphabet[i]) cnt++;
            if(cnt>1){
                cout<<"Impossible"<<endl;
                continue;
            }
        }else{
            for(int i=0; i<26; i++){
                if(alphabet[i]){
                    cout<<"Impossible"<<endl;
                    goto label;
                }
            }
        }
        while(sz>2){
            int i, j;
            for(i=sz-1; i>=0; i--)
                if(s[0]==s[i]) break;
            for(j=0; j<sz; j++)
                if(s[sz-1]==s[j]) break;
            (sz-1-i<j)?(s.erase(s.begin()+i), s.erase(s.begin()), tot+=sz-1-i):(s.erase(s.begin()+sz-1), s.erase(s.begin()+j), tot+=j);
            sz-=2;
        }
        cout<<tot<<endl;
        label:;
    }
    return 0;
}
