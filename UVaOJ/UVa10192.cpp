#include <iostream>
#include <cstring>
using namespace std;
int N1, N2, dp[105][105], cs=1;
string a1, a2;
int main(){
    while(getline(cin, a1)){
        if(a1=="#") break;
        getline(cin, a2);
        N1=a1.length(), N2=a2.length();
        int golmax=0;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<N2; i++){
            for(int j=0; j<N1; j++){
                if(a2[i]==a1[j]){
                    int mmax=1;
                    for(int ii=0; ii<i; ii++)
                        for(int jj=0; jj<j; jj++)
                            if(dp[ii][jj]+1>mmax) mmax=dp[ii][jj]+1;
                    dp[i][j]=mmax;
                    if(dp[i][j]>golmax) golmax=dp[i][j];
                }
            }
        }
        cout<<"Case #"<<cs++<<": you can visit at most "<<golmax<<" cities."<<endl;
    }
    return 0;
}
