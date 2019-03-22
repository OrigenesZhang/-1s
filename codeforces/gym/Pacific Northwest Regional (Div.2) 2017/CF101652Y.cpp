#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
ll K, P, X;
double f(ll M){
    return M*X+double(K)/M*P;
}
int main() {
//    ll K, P, X;
    cin>>K>>P>>X;
    double M=sqrt(K*P/X);
    ll m1=floor(M), m2=ceil(M);
    printf("%.3lf\n", min(f(m1), f(m2)));
    return 0;
}
