#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int n;
double X, V, s=0;
int main(){
    cout<<fixed<<setprecision(3);
    cin>>n>>X>>V;
    for(int i=0; i<n; i++){
        double l, r, v;
        cin>>l>>r>>v;
        s+=(r-l)*v;
    }
//    cout<<X<<' '<<fabs(s)<<endl;
    double vy=fabs(s)/X;
//    cout<<vy<<endl;
    if(vy-V*sqrt(3)/2>1e-5){
        cout<<"Too hard"<<endl;
        return 0;
    }
    cout<<X/sqrt(V*V-vy*vy)<<endl;
    return 0;
}
