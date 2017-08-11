//数学题中间混进一道图论...
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int index, dist;
    bool operator < (const node rhs) const{
        return dist>rhs.dist;
    }
};
struct tree{
    int dist;
    vector<node> son;
    void init(){
        dist=0;
        son.clear();
    }
}t[10010];
int mmax;
string s;
int dfs(int i, int f){
    if(t[i].son.size()==1-(i==1)) return t[i].dist=0;
    if(t[i].son.size()==2-(i==1))
        return t[i].dist=(t[i].son[0].index==f)?(dfs(t[i].son[1].index, i)+t[i].son[1].dist):(dfs(t[i].son[0].index, i)+t[i].son[0].dist);
    for(int j=0; j<t[i].son.size(); j++){
        if(t[i].son[j].index==f){
            t[i].son[j].dist=0;
            continue;
        }
        t[i].son[j].dist=dfs(t[i].son[j].index, i)+t[i].son[j].dist;
    }
    sort(t[i].son.begin(), t[i].son.end());
    mmax=max(mmax, t[i].son[0].dist+t[i].son[1].dist);
    return t[i].dist=t[i].son[0].dist;
}
int main(){
    for(int i=1; i<=10000; i++) t[i].init();
    while(getline(cin, s)){
        if(s==""){
            mmax=0;
            mmax=max(dfs(1, 0), mmax);
            cout<<mmax<<endl;
            for(int i=1; i<=10000; i++) t[i].init();
        }else{
            stringstream ss(s);
            int v1, v2, d;
            ss>>v1>>v2>>d;
            t[v1].son.push_back({v2, d});
            t[v2].son.push_back({v1, d});
        }
    }
    mmax=0;
    mmax=max(dfs(1, 0), mmax);
    cout<<mmax<<endl;
    return 0;
}
