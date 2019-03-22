#include <iostream>
#include <cstring>
using namespace std;
int N1, N2, a1[105], a2[105], dp[105][105], cs=1;
int main(){
    while(cin>>N1>>N2){
        if(!N1&&!N2) break;
        if(N1<N2){
            for(int i=0; i<N1; i++)
                cin>>a2[i];
            for(int i=0; i<N2; i++)
                cin>>a1[i];
            swap(N1, N2);
        }else{
            for(int i=0; i<N1; i++)
                cin>>a1[i];
            for(int i=0; i<N2; i++)
                cin>>a2[i];
        }
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
        cout<<"Twin Towers #"<<cs++<<endl;
        cout<<"Number of Tiles : "<<golmax<<endl;
        cout<<endl;
    }
    return 0;
}
