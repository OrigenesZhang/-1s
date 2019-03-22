#include <iostream>
using namespace std;
const int maxn=7489;
int coins[5]={1, 5, 10, 25, 50}, table[5][7500], num;
int main(){
    for(int i=0; i<=maxn; i++) table[0][i]=1;
    for(int i=0; i<5; i++)
        table[1][i]=table[2][i]=table[3][i]=table[4][i]=1;
    for(int i=1; i<5; i++)
        for(int j=5; j<=maxn; j++)
            for(int k=0; k<=i; k++)
                if(j>=coins[k]) table[i][j]+=table[k][j-coins[k]];
    while(cin>>num)
        cout<<table[4][num]<<endl;
    return 0;
}
