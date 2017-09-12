#include <iostream>
#include <cstring>
using namespace std;
int red[1050], T, N, res;
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        res=0;
        memset(red, 0, sizeof(red));
        for(int i=1; i<=N; i++){
            for(int j=0; j<N-i; j++){
                int tmp;
                cin>>tmp;
                red[i]+=tmp;
                red[i+j+1]+=tmp;
            }
            res+=red[i]*(N-1-red[i]);//统计异色三角形
        }
        cout<<N*(N-1)*(N-2)/6-res/2<<endl;
    }
    return 0;
}
