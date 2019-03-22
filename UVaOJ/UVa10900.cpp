#include <iostream>
#include <iomanip>
using namespace std;
int n;
double E[40], t;
int main(){
    cout<<fixed<<setprecision(3);
    while(cin>>n>>t){
        if(!n) break;
        E[n]=1<<n;
        for(int i=n-1; i>=0; i--){
            double p0=max(t, (double)(1<<i)/E[i+1]);
            E[i]=(1<<i)*(p0-t)/(1-t)+(1+p0)/2*E[i+1]*(1-(p0-t)/(1-t));
        }
        cout<<E[0]<<endl;
    }
    return 0;
}
