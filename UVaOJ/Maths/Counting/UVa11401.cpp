#include <iostream>
using namespace std;
long long res[1000000+50], n;
int main(){
    for(long long i=4; i<=1000000; i++)
        res[i]=res[i-1]+((i-1)*(i-2)/2-(i-1)/2)/2;
    while(cin>>n){
        if(n<3) break;
        cout<<res[n]<<endl;
    }
    return 0;
}
