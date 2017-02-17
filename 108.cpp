#include <iostream>
using namespace std;
int N, sum[110], data[110][110];
int maxcontsum(){
    int maxsum=-128, localsum=0;
    for(int i=0; i<N; i++){
        if(localsum>=0) localsum+=sum[i];
        else localsum=sum[i];
        maxsum=maxsum>localsum?maxsum:localsum;
    }
    return maxsum;
}
int main(){
    cin>>N;
    int maxsum=-128, tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>data[i][j];
            sum[j]=data[i][j];
        }
        tmp=maxcontsum();
        maxsum=maxsum>tmp?maxsum:tmp;
        for(int j=i-1; j>=0; j--){
            for(int k=0; k<N; k++)
                sum[k]+=data[j][k];//叠加后求最大连续和
            tmp=maxcontsum();
            maxsum=maxsum>tmp?maxsum:tmp;
        }
    }
    cout<<maxsum<<endl;
    return 0;
}
