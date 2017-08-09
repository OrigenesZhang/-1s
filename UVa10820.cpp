#include <iostream>
#include <cstring>
using namespace std;
int phi[50005], N;
void phi_table(int n){
    memset(phi, 0, sizeof(phi));
    phi[1]=1;
    for(int i=2; i<=n; i++){
        if(!phi[i]){
            for(int j=i; j<=n; j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main(){
    phi_table(50000);
    while(cin>>N){
        if(!N) break;
        int tot=0;
        for(int i=1; i<=N; i++) tot+=2*phi[i];
        cout<<--tot<<endl;
    }
    return 0;
}
