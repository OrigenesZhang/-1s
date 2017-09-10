#include <iostream>
using namespace std;
const int MOD=1000007;
int T, M, N, K, c[510][510];
int main(){
    for(int i=0; i<=500; i++){
        c[i][0]=c[i][i]=1;
        for(int j=1; j<i; j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
    cin>>T;
    for(int cs=1; cs<=T; cs++){
        cout<<"Case "<<cs<<": ";
        cin>>N>>M>>K;
        int res=0;
        for(int state=0; state<16; state++){
            bool even=false;
            int row=N, col=M;
            if(state&1){
                row--;
                even^=1;
            }
            if(state&2){
                row--;
                even^=1;
            }
            if(state&4){
                col--;
                even^=1;
            }
            if(state&8){
                col--;
                even^=1;
            }
            if(even) res=(res+MOD-c[row*col][K])%MOD;
            else res=(res+c[row*col][K])%MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
