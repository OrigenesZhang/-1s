#include <iostream>
#include <cmath>
using namespace std;
long long N, cnt=1;
int main(){
    while(cin>>N){
        if(!N) break;
        long long upp=sqrt(N)+0.5, tot=0, n=N;
        bool flag=true;
        for(int i=2; i<=upp; i++){
            long long tmp=1;
            while(!(N%i)){
                tmp*=i;
                N/=i;
                flag=false;
            }
            if(tmp>1) tot+=tmp;
            if(tmp==n) flag=true;
            if(N==1) break;
        }
        cout<<"Case "<<cnt++<<": ";
        if(flag) cout<<n+1<<endl;
        else if(N>upp) cout<<tot+N<<endl;
        else cout<<tot<<endl;
    }
    return 0;
}
/*
2147483647
4
0
*/
