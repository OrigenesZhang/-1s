#include <iostream>
#include <cstring>
using namespace std;
int T, N, mmap[10];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        if(N==0||N==1){
            cout<<N<<endl;
            continue;
        }
        int cur=9;
        memset(mmap, 0, sizeof(mmap));
        while(cur>1&&N>1){
            if(!(N%cur)){
                N/=cur;
                mmap[cur]++;
            }
            else cur--;
        }
        if(N!=1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=2; i<=9; i++){
            for(int j=mmap[i]; j>0; j--)
                cout<<i;
        }
        cout<<endl;
    }
    return 0;
}
