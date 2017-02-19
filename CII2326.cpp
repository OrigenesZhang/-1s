//Taejon regional 2001;
//The problem can also be solved greedly;
//The algorithm is to count the times that segiments pass a specific point;
#include <iostream>
#include <cstring>
using namespace std;
int T, N, table[200];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        memset(table, 0, sizeof(table));
        for(int i=0; i<N; i++){
            int s, t;
            cin>>s>>t;
            s=(s-1)/2;
            t=(t-1)/2;
            if(s>t) swap(s, t);//样例坑爹WA了一次
            for(int j=s; j<=t; j++)
                table[j]++;
        }
        int mmax=table[0];
        for(int i=1; i<200; i++)
            mmax=mmax<table[i]?table[i]:mmax;
        cout<<mmax*10<<endl;
    }
    return 0;
}
