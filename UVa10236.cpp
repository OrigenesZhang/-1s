#include <iostream>
#include <cmath>
using namespace std;
int primelst[23000], N;
double fib[250000];
int main(){
    primelst[1]=2;
    int cur=3;
    for(int i=2; i<=22000; i++){
        while(1){
            int upp=sqrt(cur)+0.5;
            bool flag=true;
            for(int j=1; j<i&&j<=upp; j++){
                if(!(cur%primelst[j])){
                    flag=false;
                    break;
                }
            }
            if(flag){
                primelst[i]=cur;
                cur+=2;
                break;
            }
            cur+=2;
        }
    }
    fib[1]=1;
    fib[2]=1;
    bool flag=false;
    for(int i=3; i<250000; i++){
        fib[i]=fib[i-1]+(flag?fib[i-2]/10:fib[i-2]);
        flag=false;
        while(fib[i]>=1000000000){
            fib[i]/=10;
            flag=true;
        }
    }
    while(cin>>N){
        if(N==1){
            cout<<2<<endl;
            continue;
        }
        if(N==2){
            cout<<3<<endl;
            continue;
        }
        cout<<int(fib[primelst[N]])<<endl;
    }
    return 0;
}
