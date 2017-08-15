#include <iostream>
#include <iomanip>
using namespace std;
long long n;
double q[1000000], tot=1;
int cnt[1000000];
int main(){
    q[0]=1;
    cnt[0]=0;
    for(long long i=1; i<1000000; i++){
        double p=1.0/(i*i+i);
        q[i]=(1-p)*q[i-1];
        tot*=p;
        cnt[i]=cnt[i-1];
        while(tot<1e-1){
            tot*=10;
            cnt[i]++;
        }
    }
    cout<<fixed<<setprecision(6);
    while(cin>>n){
        cout<<setprecision(6)<<1-q[n];
        cout<<' '<<setprecision(0)<<cnt[n]<<endl;
    }
    return 0;
}
