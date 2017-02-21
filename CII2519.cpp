//Beijing regional 2002;
//Choosing points from segment;
//The node struct may be omitted;
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    int x, y;
    bool operator < (const node& b) const{
        return x<b.x;
    }
}p[1010];
int n, d, tot, cs=1;
int main(){
    while(cin>>n>>d){
        if(!n&&!d) break;
        tot=0;
        for(int i=0; i<n; i++){
            cin>>p[i].x>>p[i].y;
            if(p[i].y>d) tot=-1;
        }
        if(tot==-1){
            cout<<"Case "<<cs++<<": "<<-1<<endl;
            continue;
        }
        sort(p, p+n);
        double tmp=sqrt((p[0].y+d)*(d-p[0].y));
        double cur=p[0].x+tmp;
        tot=1;
        for(int i=1; i<n; i++){
            tmp=sqrt((p[i].y+d)*(d-p[i].y));
            double l=p[i].x-tmp, r=p[i].x+tmp;
            if(l>cur) tot++, cur=r;
            else cur=min(cur, r);
        }
        cout<<"Case "<<cs++<<": "<<tot<<endl;
    }
    return 0;
}
