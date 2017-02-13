#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    double x, y;
    bool operator < (const node &b) const{
        return x<b.x;
    }
}data[10000+10];
int solve(int m, int l){
    double rr=0;
    int cnt=0, i, j;
    for(i=0; i<m; i=j){
        if(data[i].x>rr) break;
        for(j=i+1; j<m&&data[j].x<=rr; j++)
            if(data[j].y>data[i].y) i=j;
        cnt++;
        rr=data[i].y;
        if(rr>=l) break;
    }
    if(rr>=l) return cnt;
    return -1;
}
int main(){
    int n, l;
    double w;
    while(cin>>n>>l>>w){
        w/=2.0;
        int i, m=0;
        for(i=0; i<n; i++){
            int p, r;
            cin>>p>>r;
            if(r>w){
                double tmp=sqrt((double)r*r-w*w);
                data[m].x=(double)p-tmp;
                data[m++].y=(double)p+tmp;
            }
        }
        sort(data, data+m);
        cout<<solve(m, l)<<endl;
    }
    return 0;
}
