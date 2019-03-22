#include <iostream>
using namespace std;
int coins[]={1, 5, 10, 25, 50}, n;
long long table[5][30005];//overflow
int main(){
    for(int i=0; i<=30000; i++) table[0][i]=1;
    for(int i=0; i<5; i++)
        table[1][i]=table[2][i]=table[3][i]=table[4][i]=1;
    for(int i=1; i<5; i++)
        for(int j=5; j<=30000; j++)
            for(int k=0; k<=i; k++)
                if(j>=coins[k]) table[i][j]+=table[k][j-coins[k]];
    while(cin>>n){
        if(n<5) cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        else cout<<"There are "<<table[4][n]<<" ways to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}
