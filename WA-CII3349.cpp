//Verdict: Wrong Answer;
//Taipei regional 2005;
//Probably a greedy algorithm should be used;
//UDebug for this question is not working.
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
const double eps=1e-6;
int n, p;
double b, t;
struct node{
    int ddl, dist;
    bool operator < (const node& b) const{
        return dist<b.dist;
    }
};
list<node> lleft, rright;
vector<node> vl, vr;
int main(){
    while(scanf("%d", &n)){
        if(!n) break;
        scanf("%lf%d", &b, &p);
        vl.clear();
        vr.clear();
        for(int i=0; i<n; i++){
            int loc;
            scanf("%d", &loc);
            if(loc>p){
                node tmp;
                tmp.dist=loc-p;
                scanf("%d", &tmp.ddl);
                vr.push_back(tmp);
            }else{
                node tmp;
                tmp.dist=p-loc;
                scanf("%d", &tmp.ddl);
                vl.push_back(tmp);
            }
        }
        t=0;
        bool flag=true;
        if(vl.empty()){
            int sz=vr.size();
            for(int i=0; i<sz; i++){
                if(b*(double)vr[i].dist>(double)vr[i].ddl+eps){
                    flag=false;
                    break;
                }
            }
            if(!flag) printf("-1\n");
            else{
                sort(vr.begin(), vr.end());
                t=(double)vr[sz-1].dist*b;
                printf("%f\n", t);
            }
            continue;
        }
        if(vr.empty()){
            int sz=vl.size();
            for(int i=0; i<sz; i++){
                if(b*(double)vl[i].dist>(double)vl[i].ddl+eps){
                    flag=false;
                    break;
                }
            }
            if(!flag) printf("-1\n");
            else{
                sort(vl.begin(), vl.end());
                t=(double)vl[sz-1].dist*b;
                printf("%f\n", t);
            }
            continue;
        }
        sort(vl.begin(), vl.end());
        sort(vr.begin(), vr.end());
        lleft.clear();
        rright.clear();
        int sz=vl.size();
        lleft.push_front(vl[sz-1]);
        for(int i=sz-2; i>=0; i--)
            if(lleft.front().ddl>b*(double)(lleft.front().dist-vl[i].dist)+(double)vl[i].ddl+eps) lleft.push_front(vl[i]);
        sz=vr.size();
        rright.push_front(vr[sz-1]);
        for(int i=sz-2; i>=0; i--)
            if(rright.front().ddl>b*(double)(rright.front().dist-vr[i].dist)+(double)vr[i].ddl+eps) rright.push_front(vr[i]);
        int cur=0;
        while(!rright.empty()&&!lleft.empty()){
            double t1=(double)(rright.front().dist-cur)*b;//to right;
            double t2=(double)(lleft.front().dist+cur)*b;//to left;
            if(t1>(double)rright.front().ddl-t+eps||t2>(double)lleft.front().ddl-t+eps){
                t=-1;
                break;
            }
            bool flag1=2*t1+t2<(double)lleft.front().ddl-t+eps;//to right;
            bool flag2=2*t2+t1<(double)rright.front().ddl-t+eps;//to left;
            if(!flag1&&!flag2){
                t=-1;
                break;
            }
            if(flag1&&flag2){
                bool flag11=2*b*(double)(lleft.back().dist+cur)+t1<(double)rright.front().ddl-t+eps;//to leftmost;
                bool flag22=2*b*(double)(rright.back().dist-cur)+t2<(double)lleft.front().ddl-t+eps;//to rightmost;
                if(flag11&&flag22){
                    if(lleft.back().dist+cur>rright.back().dist-cur){
                        t+=b*(double)(rright.back().dist-cur);
                        cur=rright.back().dist;
                        rright.clear();
                    }else{
                        t+=b*(double)(lleft.back().dist+cur);
                        cur=-lleft.back().dist;
                        lleft.clear();
                    }
                }else if(flag11){
                    t+=b*(double)(lleft.back().dist+cur);
                    cur=-lleft.back().dist;
                    lleft.clear();
                }else if(flag22){
                    t+=b*(double)(rright.back().dist-cur);
                    cur=rright.back().dist;
                    rright.clear();
                }else{
                    if(rright.front().dist-cur>lleft.front().dist+cur){
                        auto it=lleft.begin();
                        ++it;
                        if((double)rright.front().ddl-t+eps>t1+2*b*(double)((*it).dist+cur)||(double)(*it).ddl-t+eps>2*(t1+t2)+b*(double)((*it).dist+cur)){
                            t+=t2;
                            cur=-lleft.front().dist;
                            lleft.pop_front();
                        }else{
                            t+=t1;
                            cur=rright.front().dist;
                            rright.pop_front();
                        }
                    }else{
                        auto it=rright.begin();
                        ++it;
                        if((double)lleft.front().ddl-t+eps>t2+2*b*(double)((*it).dist-cur)||(double)(*it).ddl-t+eps>2*(t1+t2)+b*(double)((*it).dist-cur)){
                            t+=t1;
                            cur=rright.front().dist;
                            rright.pop_front();
                        }else{
                            t+=t2;
                            cur=-lleft.front().dist;
                            lleft.pop_front();
                        }
                    }
                }
            }else if(flag1){
                t+=t1;
                cur=rright.front().dist;
                rright.pop_front();
            }else{
                t+=t2;
                cur=-lleft.front().dist;
                lleft.pop_front();
            }
        }
        if(t<-0.5){
            printf("-1\n");
            continue;
        }
        if(lleft.empty()){
            if(b*(double)(rright.front().dist-cur)+t>(double)rright.front().ddl+eps){
                printf("-1\n");
                continue;
            }
            t+=b*(double)(rright.back().dist-cur);
            printf("%f\n", t);
        }else{
            if(b*(double)(lleft.front().dist+cur)+t>(double)lleft.front().ddl+eps){
                printf("-1\n");
                continue;
            }
            t+=b*(double)(lleft.back().dist+cur);
            printf("%f\n", t);
        }
    }
    return 0;
}
