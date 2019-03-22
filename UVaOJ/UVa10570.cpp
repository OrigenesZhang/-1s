//纯暴力无技巧居然过了orz
#include <iostream>
#include <cstring>
using namespace std;
int num[1005], inv[1005], N;
int search(int* ar){
    int ans=0, arr[505];
    memcpy(arr+1, ar+1, N*sizeof(int));
    for(int i=1; i<N; i++){
        if(arr[i]!=i){
            for(int j=i+1; j<=N; j++){
                if(arr[j]==i){
                    swap(arr[i], arr[j]);
                    break;
                }
            }
            ans++;
        }
    }
    return ans;
}
int main(){
    while(cin>>N){
        if(!N) break;
        for(int i=1; i<=N; i++){
            cin>>num[i];
            inv[2*N+1-i]=inv[N+1-i]=num[N+i]=num[i];
        }
        int mmin=1<<30;
        for(int i=0; i<N; i++){
            mmin=min(search(num+i), mmin);
            mmin=min(search(inv+i), mmin);
        }
        cout<<mmin<<endl;
    }
    return 0;
}
