#include <iostream>
#include <cstdlib>
using namespace std;
int n;
int main(){
    while(cin>>n){
        if(!n) break;
        long long cnt=0, cur=0;
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            cnt+=abs(cur);
            cur+=tmp;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
