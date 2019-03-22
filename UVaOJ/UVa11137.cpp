#include <iostream>
using namespace std;
const int maxn=10000;
int coins[21], num;
long long table[21][10005];
int main(){
    for(int i=0; i<21; i++)
        coins[i]=(i+1)*(i+1)*(i+1);
    for(int i=0; i<=maxn; i++)
        table[0][i]=1;
    for(int i=0; i<8; i++)
        for(int j=1; j<21; j++)
            table[j][i]=1;
    for(int i=1; i<21; i++)
        for(int j=8; j<=maxn; j++)
            for(int k=0; k<=i; k++)
                if(j>=coins[k]) table[i][j]+=table[k][j-coins[k]];
    while(cin>>num)
        cout<<table[20][num]<<endl;
    return 0;
}
