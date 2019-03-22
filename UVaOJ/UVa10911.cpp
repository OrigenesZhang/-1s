#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct node{
    double x, y;
}table[20];
double d[1<<20];
int N, cs=1;
string s;
inline double dist(node n1, node n2){
    return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
double dp(int cur){
    if(d[cur]>-0.5) return d[cur];
    double tmp, mmin=(1<<30);
    for(int i = 0; i<N; i++){
        if((1<<i)&cur){
            for(int j=i+1; j<N; j++){
                if((1<<j)&cur){
                    tmp=dp(cur^(1<<i)^(1<<j))+d[(1<<i)+(1<<j)];
                    mmin=min(tmp, mmin);
                }
            }
        }
    }
    return d[cur]=mmin;
}
int main(){
    while(cin>>N){
        if(!N) break;
        N<<=1;
        for(int i=0; i<N; i++)
            cin>>s>>table[i].x>>table[i].y;
        for(int i=1; i<(1<<N); i++)
            d[i]=-1;
        d[0]=0;
        for(int i=0; i<N; i++)
            for(int j=i+1; j<N; j++)
                d[(1<<i)+(1<<j)]=dist(table[i], table[j]);
        cout<<"Case "<<cs++<<": "<<fixed<<setprecision(2)<<dp((1<<N)-1)<<endl;
    }
    return 0;
}
