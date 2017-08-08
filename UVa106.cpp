#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int N, x, y, z;
bool vis[1000010];
int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}
int main(){
    while(cin>>N){
        memset(vis, false, sizeof(vis));
        int upp=sqrt(N)+0.5, cnt=0, p=0;
        for(int m=1; m<=upp; m++){
            int up=sqrt(N-m*m)+0.5;
            up=min(up, upp);
            for(int n=m+1; n<=up; n++){
                if((m&1)!=(n&1)&&gcd(m, n)==1){
                    x=2*m*n;
                    y=n*n-m*m;
                    z=m*m+n*n;
                    if(z>N) continue;//不判定会出现z>N的情况,因为之前的up和upp都是四舍五入的
                    cnt++;
                    for(int i=1; i*z<=N; i++)
                        vis[i*x]=vis[i*y]=vis[i*z]=true;
                }
            }
        }
        for(int i=1; i<=N; i++) p+=(!vis[i]);
        cout<<cnt<<' '<<p<<endl;
    }
    return 0;
}
