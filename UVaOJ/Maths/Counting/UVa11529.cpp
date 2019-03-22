#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
const double pi=4.0*atan(1.0);
const double eps=1e-8;
int N, cs=1;
double tot;
struct Point{
    double x, y, angle;
    Point(double a=0, double b=0):x(a), y(b){
        angle=atan2(b, a);
    }
    bool operator < (const Point& rhs)const{
        return angle<rhs.angle;
    }
}P[1210];
int main(){
    cout<<fixed<<setprecision(2);
    while(cin>>N){
        if(!N) break;
        cout<<"City "<<cs++<<": ";
        if(N<=3){
            cout<<"0.00"<<endl;
            continue;
        }
        tot=0;
        for(int i=0; i<N; i++)
            cin>>P[i].x>>P[i].y;
        for(int i=0; i<N; i++){
            Point cur[2410];
            int cnt=0;
            for(int j=0; j<N; j++){
                if(i==j) continue;
                cur[cnt++]=Point(P[j].x-P[i].x, P[j].y-P[i].y);
            }
            sort(cur, cur+cnt);//按极角排序
            for(int j=0; j<cnt; j++){
                cur[j+cnt]=cur[j];
                cur[j+cnt].angle+=2*pi;
            }
            double res=0;
            for(int j=0, k=1; j<cnt; j++){
                while(cur[k].angle-cur[j].angle<=pi-eps) k++;
                res+=(k-j-1)*(k-j-2)/2;
            }
            tot+=cnt*(cnt-1)*(cnt-2)/6-res;
        }
        cout<<6*tot/N/(N-1)/(N-2)<<endl;
    }
    return 0;
}
