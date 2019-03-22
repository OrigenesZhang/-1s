#include <iostream>
#include <algorithm>
using namespace std;
long long Catalan[20], s[20][20];
int n, m;
char* construct(char* str, int n, int m){
    if(!n) return str;
    if(n==1){
        *str++='E';
        *str++='S';
        return str;
    }
    int cur=upper_bound(s[n], s[n]+n, m)-s[n];
    if(cur) m-=s[n][cur-1];
    int l=m/Catalan[cur], r=m%Catalan[cur];
    *str++='E';
    str=construct(str, n-cur-1, l);
    *str++='S';
    str=construct(str, cur, r);
    return str;
}
int main(){
    Catalan[0]=1;
    for(int i=1; i<20; i++){
        s[i][0]=Catalan[i-1]*Catalan[0];
        for(int j=1; j<i; j++)
            s[i][j]=s[i][j-1]+Catalan[i-j-1]*Catalan[j];
        Catalan[i]=s[i][i-1];
    }
    while(cin>>n>>m){
        if(!n&&!m) break;
        n--;
        m--;
        if(m>=Catalan[n]){
            cout<<"ERROR"<<endl;
            continue;
        }
        char str[50];
        *construct(str, n, m)='\0';//terminate the string
        cout<<str<<endl;
    }
    return 0;
}
