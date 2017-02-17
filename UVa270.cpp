#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int T, pivotx, pivoty;
string s;
struct Point{
    int x, y;
    bool operator < (const Point& p) const{
        return (p.x-pivotx)*(y-pivoty)<(x-pivotx)*(p.y-pivoty);
    }
};
vector<Point> v;
multiset<Point> st;
inline bool cmp(Point p1, Point p2){
    if(p1.y!=p2.y) return p1.y<p2.y;
    return p1.x<p2.x;
}
int main(){
    cin>>T;
    cin.get();
    getline(cin, s);
    while(T){
        getline(cin, s);
        if(s==""){
            T--;
            sort(v.begin(), v.end(), cmp);
            int sz=v.size();
            int maxx=0;
            for(int i=0; i<sz; i++){
                st.clear();
                pivotx=v[i].x;
                pivoty=v[i].y;
                for(int j=i+1; j<sz; j++)
                    st.insert(v[j]);
                multiset<Point>::iterator it;
                int mmax=0;
                for(it=st.begin(); it!=st.end(); ++it)
                    if(st.count(*it)>mmax) mmax=st.count(*it);
                if(mmax>maxx) maxx=mmax;
            }
            cout<<maxx+1<<endl;
            if(T) cout<<endl;
            v.clear();
            continue;
        }
        int xl=0, yl=0, cur=-1;
        bool signx=true, signy=true;
        while(s.at(++cur)!=' '){
            if(s.at(cur)=='-'){
                signx=false;
                continue;
            }
            xl*=10;
            xl+=s.at(cur)-'0';
        }
        while(++cur<s.length()){
            if(s.at(cur)=='-'){
                signy=false;
                continue;
            }
            yl*=10;
            yl+=s.at(cur)-'0';
        }
        if(!signx) xl*=-1;
        if(!signy) yl*=-1;
        Point tmp;
        tmp.x=xl;
        tmp.y=yl;
        v.push_back(tmp);
    }
    return 0;
}
