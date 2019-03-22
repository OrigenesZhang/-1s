//欧拉公式:F=E-V+2
#include <iostream>
#include <cmath>
using namespace std;
long long N;
int cs=1;
inline long long solve(long long b, long long c){
    long long n=(sqrt(b*b+4*c)-b)/2+0.5;
    if(n*n+b*n==c&&n<20000) return n;//注意判断在范围内(uDebug数据弱)
    return -1;
}
int main(){
    while(cin>>N){
        if(N==-1) break;//终止条件题目里面讲得不清楚
        cout<<"Case "<<cs++<<':'<<endl;
        if(N==1){//特判边界情况
            cout<<"0 0 0"<<endl;
            continue;
        }
        bool flag=false;
        for(long long m=0; m<100; m++){
            long long r=N-2*m*(m-1)-2;
            if(r<0) break;
            for(long long p=99; p>=0; p--){
                long long cur=r-6*m*p-3*p*(p-1);
                if(cur<0) continue;
                long long n=solve(4*m+6*p-1, cur);
                if(n==-1) continue;
                flag=true;
                cout<<m<<' '<<n<<' '<<p<<endl;
            }
        }
        if(!flag) cout<<"Impossible."<<endl;
    }
    return 0;
}
