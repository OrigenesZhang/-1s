#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-8;
const double pi=4.0*atan(1.0);
struct Point{
    double x, y, angle;
    Point(double a=0, double b=0):x(a), y(b){
        angle=atan2(b, a);
    }
    bool operator < (const Point& rhs)const{
        return angle<rhs.angle;
    }
}P[1210];
int cs=1, N, cnt;
int main(){
    while(cin>>N){
        if(!N) break;
        cnt=0;
        for(int i=0; i<N; i++)
            cin>>P[i].x>>P[i].y;
        if(N<=2){
            cout<<"Scenario "<<cs++<<":\nThere are 0 sites for making valid tracks"<<endl;
            continue;
        }
        for(int i=0; i<N; i++){
            Point cur[2410];
            int Cnt=0;
            for(int j=0; j<N; j++){
                if(i==j) continue;
                cur[Cnt++]=Point(P[j].x-P[i].x, P[j].y-P[i].y);
            }
            sort(cur, cur+Cnt);
            for(int j=0; j<Cnt; j++){
                cur[Cnt+j]=cur[j];
                cur[Cnt+j].angle+=2*pi;
            }
            int tot=0, Cur=1;
            for(int j=0; j<Cnt; j++){
                while(fabs(cur[Cur].angle-cur[j].angle)<pi/2-eps) Cur++;
                tot+=Cur-j-1;
            }
            cnt+=Cnt*(Cnt-1)/2-tot;
        }
        cout<<"Scenario "<<cs++<<":\nThere are "<<N*(N-1)*(N-2)/6-cnt<<" sites for making valid tracks"<<endl;
    }
    return 0;
}
