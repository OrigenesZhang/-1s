#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double E=3.5;
const double eps=1e-4;
inline bool equals(double a, double b){
    return fabs(a-b)<eps;
}
double p[15], ex, mmax;
int main(){
    cout<<fixed<<setprecision(3);
    for(int i=1; i<=6; i++){
        cin>>p[i];
        ex+=p[i]*i;
        mmax=max(p[i], mmax);
    }
    if(equals(E, ex)){
        cout<<"0.000"<<endl;
    }else{
        cout<<fabs(E-ex)/mmax<<endl;
    }
    return 0;
}
