#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double p, q, r, s, t, u;
inline double f(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
    while(cin>>p>>q>>r>>s>>t>>u){
        double x=0, y=1;
        if(f(-1e-6)<-1e-5||f(1+1e-6)>1e-5){
            cout<<"No solution"<<endl;
            continue;
        }
        double m;
        while(y-x>1e-8){//不知道为什么1e-6一直WA改-8就A了;
            m=x+(y-x)/2;
            double fx=f(m);
            if(fx>0) x=m;
            else y=m;
        }
        printf("%.4f\n", m);
    }
    return 0;
}
