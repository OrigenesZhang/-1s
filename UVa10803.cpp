#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef pair<int, int> Point;
Point p[105];
double d[105][105];
int cs, n, CS;
double dist(Point p1, Point p2){
    int num=(p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
    if(num>100) return -1;
    return sqrt(num);
}
int main(){
    cin>>CS;
    for(cs=1; cs<=CS; cs++){
        cout<<"Case #"<<setprecision(0)<<cs<<":"<<endl;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>p[i].first>>p[i].second;
        for(int i=0; i<n; i++){
            d[i][i]=0;
            for(int j=i+1; j<n; j++){
                double tmp=dist(p[i], p[j]);
                d[i][j]=d[j][i]=tmp;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                if(d[i][k]<0) continue;
                for(int j=0; j<n; j++){
                    if(d[k][j]<0) continue;
                    if(d[i][j]<0) d[i][j]=d[i][k]+d[k][j];
                    else if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        double mmax=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j]<0){
                    cout<<"Send Kurdy"<<endl;
                    goto label;
                }
                mmax=max(mmax, d[i][j]);
            }
        }
        cout<<fixed<<setprecision(4);
        cout<<mmax<<endl;
        label:
        cout<<endl;
    }
    return 0;
}
