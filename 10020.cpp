#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int T, M, curl, curr;
struct seg{
    int l, r;
    bool operator < (const seg& b) const{
        return r<b.r;
    }
};
seg v[100000+100];//数组要开够
queue<seg> q;
inline bool cmp(seg s1, seg s2){
    if(s1.l>curl) return false;
    if(s2.l>curl) return true;
    return s1.r>s2.r;
}
int b_search(int l, int r){
    if(v[r-1].r<=curl) return -1;
    if(v[l].r>curl) return l;
    while(r-l>1){
        int m=(l+r)/2;
        if(v[m].r<=curl) l=m;
        else r=m;
    }
    return r;
}
int main(){
    cin>>T;
    while(T--){
        cin>>M;
        while(!q.empty()){
            queue<seg> tmp;
            swap(q, tmp);
        }
        int tot=0, a, b;
        while(cin>>a>>b){
            if(!(a||b)) break;
            v[tot].l=a;
            v[tot++].r=b;
        }
        int cnt=0;
        curl=0, curr=0;
        int lpos=0;
        while(curr<M){
            sort(v+lpos, v+tot);
            lpos=b_search(lpos, tot);
            if(lpos<0){
                cout<<"0"<<endl;
                goto label;
            }
            sort(v+lpos, v+tot, cmp);
            if(v[lpos].l>curl){
                cout<<"0"<<endl;
                goto label;
            }
            q.push(v[lpos]);
            curr=v[lpos].r;
            curl=curr;
            cnt++;
        }
        cout<<cnt<<endl;
        while(!q.empty()){
            cout<<q.front().l<<' '<<q.front().r<<endl;
            q.pop();
        }
        label:;
        if(T) cout<<endl;
    }
    return 0;
}
