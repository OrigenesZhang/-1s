#include <iostream>
#include <cstring>
using namespace std;
int T, N, data[160][160], sum[160], tmp[160];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin>>data[i][j];
                data[i+N][j]=data[i][j+N]=data[i+N][j+N]=data[i][j];
            }
        }
        memset(sum, 0, sizeof(sum));
        memset(tmp, 0, sizeof(tmp));
        int maxsum=-101;
        for(int u=1; u<=N; u++){
            for(int v=1; v<=N; v++){
                for(int j=0; j<N; j++){
                    for(int i=0; i<N; i++){
                        tmp[i]=data[u+i][v+j];
                        if(i) tmp[i]+=tmp[i-1];
                        if(!j) sum[i]=tmp[i];
                        else sum[i]+=tmp[i];
                        if(sum[i]>maxsum) maxsum=sum[i];
                    }
                }
            }
        }
        cout<<maxsum<<endl;
    }
    return 0;
}
