#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, h, f[30], d[30], t[30], i;
struct fish{
    int index, num;
    bool operator < (const fish& b) const{
        if(num!=b.num) return num>b.num;
        return index<b.index;
    }
};
struct Node{
    int timeremained, totfish;
    int talloc[30];
    fish fcur[30];
    inline void init(){
        memset(talloc, 0, sizeof(talloc));
        for(int j=0; j<n; j++){
            fcur[j].num=f[j];
            fcur[j].index=j;
        }
        timeremained=h*12-t[i]>0?h*12-t[i]:0;
        totfish=0;
    }
}node[30];
int main(){
    bool first=true;
    while(cin>>n){
        if(!n) break;
        cin>>h;
        int cur=n;
        for(i=0; i<n; i++)
            cin>>f[i];
        for(i=0; i<n; i++)
            cin>>d[i];
        t[0]=0;
        for(i=1; i<n; i++){
            int tmp;
            cin>>tmp;
            t[i]=tmp+t[i-1];
            if(t[i]>=12*h&&cur==n) cur=i;
        }
        for(i=0; i<cur; i++)
            node[i].init();
        for(i=0; i<cur; i++){
            while(node[i].timeremained--){
                sort(node[i].fcur, node[i].fcur+i+1);//用priority_queue会更快但是因为数据规模小就懒得改了
                node[i].totfish+=node[i].fcur[0].num;
                node[i].talloc[node[i].fcur[0].index]++;
                node[i].fcur[0].num-=d[node[i].fcur[0].index];
                if(node[i].fcur[0].num<0) node[i].fcur[0].num=0;
            }
        }
        Node mmax;
        mmax.totfish=-1;
        for(i=0; i<cur; i++)
            if(node[i].totfish>mmax.totfish) mmax=node[i];
        if(!first) cout<<endl;
        first=false;
        for(int i=0; i<n-1; i++)
            cout<<5*mmax.talloc[i]<<", ";
        cout<<5*mmax.talloc[n-1]<<endl;
        cout<<"Number of fish expected: "<<mmax.totfish<<endl;//没有THE没有THE没有THE
    }
    return 0;
}
