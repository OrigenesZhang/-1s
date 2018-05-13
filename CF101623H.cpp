#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll maxr=1000;
inline ll f(ll a, ll b, ll c){
    return a*a+b*b+c*c+7*min(min(a, b), c);
}
int n;
ll a, b, c, d;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
        ll ans=0;
        for(int i=0; i<=min(d, maxr); i++){
            for(int j=0; j<=min(d-i, maxr); j++){
                ll k=d-i-j;
                ans=max(ans, f(a+i, b+j, c+k));
                ans=max(ans, f(a+i, b+k, c+j));
                ans=max(ans, f(a+k, b+i, c+j));
            }
        }
        ans=max(ans, f(a+d, b, c));
        ans=max(ans, f(a, b+d, c));
        ans=max(ans, f(a, b, c+d));
        printf("%I64d\n", ans);
    }
    return 0;
}
