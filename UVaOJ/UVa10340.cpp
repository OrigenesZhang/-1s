#include<iostream>
using namespace std;
char s[100010], t[100010];//string装不下lol
int main(){
    while(cin>>s>>t){
        int i, j;
        for(i=0, j=0; s[i]!='\0'&&t[j]!='\0'; j++)
            if(s[i]==t[j]) i++;
        if(s[i]=='\0') cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
