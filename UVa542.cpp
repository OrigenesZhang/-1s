#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
double table[20][20], v[20], p[20];
string s[20];
inline void cal(int i, int start, int tot){
    v[i]=0;
    int cnt=0;
    while(cnt<tot)
        v[i]+=p[i+start+cnt]*table[i][i+start+cnt++];
    v[i]*=p[i];
}
int main(){
    for(int i=1; i<=16; i++) getline(cin, s[i]);
    for(int i=1; i<=16; i++)
        for(int j=1; j<=16; j++)
            cin>>table[i][j], table[i][j]/=100;
    for(int i=1; i<=16; i++)
        if(i&1) p[i]=table[i][i+1];
        else p[i]=table[i][i-1];
    for(int i=1; i<=16; i++){
        if(i%4==1) cal(i, 2, 2);
        else if(i%4==2) cal(i, 1, 2);
        else if(i%4==3) cal(i, -2, 2);
        else cal(i, -3, 2);
    }
    memcpy(p, v, sizeof(v));
    for(int i=1; i<=16; i++){
        if(i%8<5){
            if(i%8) cal(i, 5-i%8, 4);
            else cal(i, -7, 4);
        }
        else cal(i, 1-i%8, 4);
    }
    memcpy(p, v, sizeof(v));
    for(int i=1; i<=16; i++){
        if(i<=8) cal(i, 9-i, 8);
        else cal(i, 1-i, 8);
    }
    cout<<fixed<<setprecision(2);
    for(int i=1; i<=16; i++)
        cout<<left<<setw(10)<<s[i]<<" p="<<100*v[i]<<'%'<<endl;
    return 0;
}
