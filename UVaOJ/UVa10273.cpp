//暴力出奇迹[所以这个题目跟图论有什么关系呢]
#include <iostream>
#include <cstring>
using namespace std;
const int maxt=2520;
int T, N, t[1005], M[1005][12];
bool die[1005];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>t[i];
            for(int j=0; j<t[i]; j++)
                cin>>M[i][j];
        }
        memset(die, false, sizeof(die));
        int s=0, d, ds=-1;
        for(d=0; d-ds<=maxt; d++){
            int cnt=0, mmin=maxt, I=-1;
            for(int i=0; i<N; i++){
                if(die[i]) continue;
                if(M[i][d%t[i]]<mmin){
                    cnt=1;
                    I=i;
                    mmin=M[i][d%t[i]];
                }else if(M[i][d%t[i]]==mmin)
                    cnt++;
            }
            if(cnt==1){
                die[I]=true;
                s++;
                ds=d;
            }
        }
        cout<<N-s<<' '<<ds+1<<endl;
    }
    return 0;
}
