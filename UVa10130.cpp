#include <iostream>
#include <cstring>
using namespace std;
int T, N, P[1010], W[1010], G, MW[105], f[1005*105], s;
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++)
            cin>>P[i]>>W[i];
        cin>>G;
        for(int i=1; i<=G; i++)
            cin>>MW[i];
        s=0;
        for(int i=1; i<=G; i++){
            memset(f, 0, sizeof(f));
            for(int j=1; j<=N; j++){
                for(int k=MW[i]; k>=0; k--)
                    if(k>=W[j]) f[k]=max(f[k], f[k-W[j]]+P[j]);
            }
            s+=f[MW[i]];
        }
        cout<<s<<endl;
    }
    return 0;
}
