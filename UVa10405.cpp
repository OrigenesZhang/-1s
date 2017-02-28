#include <iostream>
#include <string>
using namespace std;
int table[1005][1005];
string s1, s2;
int main(){
    while(getline(cin, s1)){
        getline(cin, s2);//特例:s1==""||s2=="";
        int n=s1.length(), m=s2.length();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(!(i&&j)) table[i][j]=0;
                else if(s1.at(i-1)==s2.at(j-1)) table[i][j]=table[i-1][j-1]+1;
                else table[i][j]=max(table[i-1][j], table[i][j-1]);
            }
        }
        int mmax=-1;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                mmax=mmax<table[i][j]?table[i][j]:mmax;
        cout<<mmax<<endl;
    }
    return 0;
}
