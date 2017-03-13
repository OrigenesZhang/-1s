#include <iostream>
using namespace std;
struct s{
    int r, c;
}A[11];
int d[11][11];
void print(int l, int r){
    if(l==r){
        cout<<"A"<<l;
        return;
    }
    cout<<'(';
    print(l, d[l][r]);
    cout<<" x ";
    print(d[l][r]+1, r);
    cout<<')';
    return;
}
int main(){
    int N, cs=0;
    while(cin>>N){
        if(!N) break;
        for(int i=1; i<=N; i++)
            cin>>A[i].r>>A[i].c;
        long long int dp[11][11];
        for(int i=1; i<N; i++){
            dp[i][i+1]=A[i].r*A[i].c*A[i+1].c;
            dp[i][i]=dp[i+1][i+1]=0;
            d[i][i+1]=i;
        }
        for(int i=2; i<N; i++){
            for(int j=1; i+j<= N; j++){
                long long tmp=A[j].r*A[j].c*A[i+j].c;
                dp[j][i+j]=dp[j][j]+dp[j+1][i+j]+tmp;
                d[j][i+j]=j;
                for(int k=1; k<i; k++){
                    tmp=A[j].r*A[j+k].c*A[i+j].c;
                    long long mmin=dp[j][j+k]+dp[j+k+1][i+j]+tmp;
                    if(dp[j][i+j]>mmin){
                        dp[j][i+j]=mmin;
                        d[j][i+j]=j+k;
                    }
                }
            }
        }
        cout<<"Case "<<++cs<<": ";
        print(1, N);
        cout<<endl;
    }
    return 0;
}
