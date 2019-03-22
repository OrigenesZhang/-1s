#include <iostream>
#include <cmath>
using namespace std;
int table[20], N;
int main(){
    ios_base::sync_with_stdio(false);
    for(int i=0; i<=19; i++)
        table[i]=1<<i;
    while(cin>>N){
        if(!N) break;
        int pos=floor(log2(N));
        if(N==table[pos]){
            cout<<table[pos]<<endl;
            continue;
        }
        cout<<(N-table[pos]<<1)<<endl;
    }
    return 0;
}
