#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
int key[205], change[205][205], n, k;
string str;
char res[205];
int main(){
    ios_base::sync_with_stdio(false);
    while(cin>>n){
        if(!n) break;
        for(int i=1; i<=n; i++)
            cin>>key[i];
        for(int i=1; i<=n; i++)
            change[0][i]=i;
        for(int i=1; i<=n; i++){
            int tmp=i, j=1;
            do{
                change[i][j++]=tmp;
                tmp=key[tmp];
            }while(tmp!=i);
            change[i][0]=j-1;
        }
        string s;
        cin.get();
        while(getline(cin, s)){
            if(s=="0") break;
            stringstream ss(s);
            ss>>k;
            ss.get();
            getline(ss, str);
            int len=str.length();
            for(int i=1; i<=n; i++)
                res[i]=' ';
            res[n+1]='\0';
            for(int i=1; i<=len; i++){
                int shift=k%change[i][0];
                res[change[i][shift+1]]=str[i-1];
            }
            cout<<res+1<<endl;
        }
        cout<<endl;
    }
    return 0;
}
