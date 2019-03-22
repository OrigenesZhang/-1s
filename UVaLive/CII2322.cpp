//Taejon regional 2001;
//A straightforward greedy implementation;
//Priority queue is used to reduce time complexity;
#include <iostream>
#include <queue>
using namespace std;
struct stick{
    int l, w;
    bool operator > (const stick& b) const{
        if(l!=b.l) return l<b.l;
        return w<b.w;
    }
    bool operator < (const stick &b) const{
        if(l!=b.l) return l>b.l;
        return w>b.w;
    }
};
priority_queue<stick> s;
int T, n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++){
            stick tmp;
            cin>>tmp.l>>tmp.w;
            s.push(tmp);
        }
        int tot=0;
        while(!s.empty()){
            priority_queue<stick> tmp;
            stick cur={-1, -1};
            while(!s.empty()){
                if(s.top().w<cur.w) tmp.push(s.top());
                else cur=s.top();
                s.pop();
            }
            swap(tmp, s);
            tot++;
        }
        cout<<tot<<endl;
    }
    return 0;
}
