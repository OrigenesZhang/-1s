#include <iostream>
using namespace std;
long long n;
int main(){
    while(cin>>n){
        if(n<0) break;
        cout<<(n*(n+1)>>1)+1<<endl;
    }
    return 0;
}
