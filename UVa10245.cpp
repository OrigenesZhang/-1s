#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
struct node{
    double x, y;//题目要看清楚orz样例好坑
}data[10000+100];
const double eps=1e-7;
int n;
int main(){
    while(scanf("%d", &n)){
        if(!n) break;
        for(int i=0; i<n; i++)
            cin>>data[i].x>>data[i].y;
        double mmin=1000000000, tmp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                tmp=(data[i].x-data[j].x)*(data[i].x-data[j].x)+(data[i].y-data[j].y)*(data[i].y-data[j].y);
                if(tmp>100000000-eps) continue;
                mmin=min(tmp, mmin);
            }
        }
        if(mmin<100000000-eps) printf("%.4f\n", sqrt(mmin));
        else printf("INFINITY\n");
    }
    return 0;
}
