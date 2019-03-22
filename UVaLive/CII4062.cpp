//Dhaka regional 2007;
//Sort according to x-axis first and then y-axis;
//Rotating the coordinate system makes it easier;
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
const double pi=4.0*atan(1.0);
struct Node{
    double x, y;
    bool operator < (const Node& b) const{
        return x<b.x;
    }
}node[15010];
int N, cs=1;
double e, theta;
inline bool cmp(Node p1, Node p2){
    return p1.y<p2.y;
}
inline double area(Node p1, Node p2){
    double x=fabs(p1.x-p2.x)/2, y=fabs(p1.y-p2.y)/2;
    return ((1-e*e)*x*x+y*y)/(1-e*e);
}
int main(){
    while(cin>>N>>e>>theta){
        if(e<0.1) break;
        theta*=pi/180;
        for(int i=0; i<N; i++){
            double tmpx, tmpy;
            cin>>tmpx>>tmpy;
            node[i].x=tmpx*cos(theta)+tmpy*sin(theta);
            node[i].y=-tmpx*sin(theta)+tmpy*cos(theta);
        }
        double s=1e20;
        sort(node, node+N);
        for(int i=1; i<N; i++){
            double tmp=area(node[i-1], node[i]);
            s=s>tmp?tmp:s;
        }
        sort(node, node+N, cmp);
        for(int i=1; i<N; i++){
            double tmp=area(node[i-1], node[i]);
            s=s>tmp?tmp:s;
        }
        cout<<"Case "<<cs++<<":"<<endl;
        printf("%.6f\n", pi*s*sqrt(1-e*e));
    }
    return 0;
}
