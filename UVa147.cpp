#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=6000;
int coins[11]={1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long table[11][6005];
int main(){
    for(int i=0; i<=maxn; i++) table[0][i]=1;
    for(int i=1; i<11; i++) table[i][0]=table[i][1]=1;
    for(int i=1; i<11; i++)
        for(int j=2; j<=maxn; j++)
            for(int k=0; k<=i; k++)
                if(j>=coins[k]) table[i][j]+=table[k][j-coins[k]];
    double tmp;
    while(cin>>tmp){
        int num=tmp*20+0.5;
        if(!num) break;
        printf("%6.2f%17lld\n", tmp, table[10][num]);
    }
    return 0;
}
