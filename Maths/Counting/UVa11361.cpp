#include <iostream>
#include <cstring>
using namespace std;
int d[12][110][110], num[12], A, B, T, K, cur;
void construct(int n){
    cur=0;
    do{
        num[++cur]=n%10;
    }while(n/=10);
    for(int i=1; i<=(cur>>1); i++)
        swap(num[i], num[cur+1-i]);
}
int dp(int n){
    if(!n) return 1;
    memset(d, 0, sizeof(d));
    construct(n);
    int x=0, y=0;
    for(int i=1; i<=cur; i++){//dp
        for(int j=0; j<K; j++)
            for(int k=0; k<K; k++)
                for(int u=0; u<=9; u++)
                    d[i][(j*10+u)%K][(k+u)%K]+=d[i-1][j][k];
        for(int j=0; j<num[i]; j++)
            d[i][(x*10+j)%K][(y+j)%K]++;
        x=(x*10+num[i])%K;
        y=(y+num[i])%K;
    }
    if(!x&&!y) return ++d[cur][0][0];
    return d[cur][0][0];
}
int main(){
    cin>>T;
    while(T--){
        cin>>A>>B>>K;
        if(K>82){
            cout<<0<<endl;
            continue;
        }
        cout<<dp(B)-dp(A-1)<<endl;
    }
    return 0;
}
