//Northwestern Europe regional 2006;
//Binary search the answer;
//A pre-defined eps is important;
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi=4.0*atan(1.0);
const double eps=1e-8;
int N, F, T;
double v[10010];
bool judge(double V){
    int cur=0, cnt=0;
    double tmp=0;
    while(cur<N&&cnt<F+1){
        if(tmp+V<v[cur]+eps) tmp+=V, cnt++;
        else tmp=0, cur++;
    }
    return cnt==F+1;
}
int main(){
    cin>>T;
    while(T--){
        cin>>N>>F;
        double l=0, r=0, V;
        for(int i=0; i<N; i++){
            double tmp;
            cin>>tmp;
            v[i]=tmp*tmp*pi;
            r+=v[i];
        }
        r/=(F+1);
        while(r-l>1e-6){
            V=(l+r)/2;
            judge(V)?l=V:r=V;
        }
        printf("%.4f\n", V);
    }
    return 0;
}
