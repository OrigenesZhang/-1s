#include <iostream>
using namespace std;
int m, n;
int main(){
    while(cin>>m>>n){
        if(!m&&!n) break;
        int M=m, N=n;
        if(m>n) swap(m, n);
        if(!m){
            cout<<0<<" knights may be placed on a "<<M<<" row "<<N<<" column board."<<endl;
            continue;
        }
        if(m==1){
            cout<<n<<" knights may be placed on a "<<M<<" row "<<N<<" column board."<<endl;
            continue;
        }
        if(m==2){
            int sur=n%4;
            cout<<2*min(sur, 2)+n/4*4<<" knights may be placed on a "<<M<<" row "<<N<<" column board."<<endl;
            continue;
        }
        cout<<m*n/2+(m*n&1)<<" knights may be placed on a "<<M<<" row "<<N<<" column board."<<endl;
    }
    return 0;
}
