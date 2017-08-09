#include <iostream>
using namespace std;
long long n, t, coins[55], c, table;
long long gcd(long long a, long long b){
    return b?gcd(b, a%b):a;
}
long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}
int main(){
    while(cin>>n>>t){
        if(!n&&!t) break;
        for(int i=1; i<=n; i++)
            cin>>coins[i];
        for(int T=0; T<t; T++){
            cin>>table;
            long long mmax=-1, mmin=-1;
            for(int i=4; i<=n; i++){
                for(int j=3; j<i; j++){
                    for(int k=2; k<j; k++){
                        for(int l=1; l<k; l++){
                            c=lcm(lcm(coins[i], coins[j]), lcm(coins[k], coins[l]));
                            if(!(table%c)){
                                mmax=table;
                                mmin=table;
                                goto label;
                            }
                            if(mmax==-1){
                                mmin=table/c*c;
                                mmax=mmin+c;
                            }else{
                                mmin=max(table/c*c, mmin);
                                mmax=min(table/c*c+c, mmax);
                            }
                        }
                    }
                }
            }
            label:
            cout<<mmin<<' '<<mmax<<endl;
        }
    }
    return 0;
}
