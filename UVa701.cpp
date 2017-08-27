#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double n;
    while(cin>>n){
        int cur=log10(n)+2;
        while(1){
            int low=floor(log2(n)+cur*log2(10));
            int high=ceil(log2(n+1)+cur*log2(10));
            if(high>low+1){
                cout<<low+1<<endl;
                break;
            }
            cur++;
        }
    }
    return 0;
}
