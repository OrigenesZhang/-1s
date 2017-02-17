#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct job{
    int index, cost, time;
    bool operator < (const job& b)const{
        if(cost*b.time!=time*b.cost) return cost*b.time>b.cost*time;
        return index<b.index;
    }
};
vector<job> v;
int T, N;
int main(){
    cin>>T;
    while(T--){
        v.clear();
        cin>>N;
        for(int i=1; i<=N; i++){
            job tmp;
            cin>>tmp.time>>tmp.cost;
            tmp.index=i;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<N; i++){
            cout<<v[i].index;
            if(i!=N-1) cout<<' ';
        }
        cout<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
//这题有毛病，有行末空格就是PE
