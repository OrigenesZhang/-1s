#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n, k;
    cin>>n;
    while(n--){
        cin>>k;
        if(k==2){
            cout<<"0.0000"<<endl;
            continue;
        }
        k>>=1;
        k--;
        long double res=1;
        cout<<fixed<<setprecision(4);
        int tot=k<<1;
        for(int i=0; i<k; i++){
            res*=((long double)(2*k-i))/(k-i);
            while(res>1) res/=2, tot--;
        }
        while(tot--) res/=2;
        cout<<(double)(1-res)<<endl;
    }
    return 0;
}
