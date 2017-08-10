#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int first3(int x, int k){
    double tmp=k*log10(x);
    return floor(pow(10, tmp-floor(tmp))*100);
}
int last3(int x, int k){
    int product=1, base=x;
    while(k){
        if(k&1){
            product*=base;
            product%=1000;
        }
        base*=base;
        base%=1000;
        k>>=1;
    }
    return product;
}
int T, n, k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int last=n%1000;
        cout<<first3(n, k)<<"...";
        cout<<setfill('0')<<setw(3);
        cout<<last3(last, k)<<endl;
    }
    return 0;
}
