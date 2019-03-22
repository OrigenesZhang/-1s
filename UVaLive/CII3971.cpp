//Northwestern Europe regional 2007;
//Use binary search to find the answer;
//Convert construction to judgement;
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string, int> mmap;
vector<pair<int, int>> v[1010];
int T, n, b, tot;
bool judge(int ans){
    int sum=0;
    for(int i=1; i<=tot; i++){
        int tmp=1e9+1, sz=v[i].size();
        for(int j=0; j<sz; j++)
            if(v[i][j].second>=ans) tmp=min(tmp, v[i][j].first);
        if(tmp==1e9+1) return false;
        sum+=tmp;
        if(sum>b) return false;
    }
    return true;
}
int main(){
    cin>>T;
    while(T--){
        tot=0;
        mmap.clear();
        cin>>n>>b;
        string s;
        int x,y, l=0, r=0;
        for(int i=1; i<=n; i++){
            cin>>s;
            if(!mmap[s]) mmap[s]=++tot, v[tot].clear();
            int cur=mmap[s];
            cin>>s>>x>>y;
            r=max(r,y);
            v[cur].push_back(make_pair(x, y));
        }
        r++;
        while(l<r){
            int m=l+(r-l)/2;
            if(judge(m)) l=m+1;
            else r=m;
        }
        cout<<l-1<<endl;
    }
    return 0;
}
