#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps=1e-8;
int S, i, n;
double p;
int main(){
    cin>>S;
    cout<<fixed<<setprecision(4);
    while(S--){
        cin>>n>>p>>i;
        if(p<eps){//p==0
            cout<<"0.0000"<<endl;
            continue;
        }
        cout<<pow(1-p, i-1)*p/(1-pow(1-p, n))<<endl;
    }
    return 0;
}
