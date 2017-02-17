#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<int> v;
multiset<int> s;
int main(){
    while(scanf("%d", &n)==1){
        v.clear();
        s.clear();
        for(int i=0; i<n; i++){
            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
            s.insert(tmp);
        }
        sort(v.begin(), v.end());
        int o1, o2, o3;
        if(n&1){
            o1=v[n/2];
            o2=s.count(o1);
            o3=1;
        }else{
            o1=v[n/2-1];
            if(v[n/2-1]==v[n/2]){
                o2=s.count(o1);
                o3=1;
            }else{
                o2=s.count(o1)+s.count(v[n/2]);
                o3=v[n/2]-o1+1;
            }
        }
        printf("%d %d %d\n", o1, o2, o3);
    }
    return 0;
}
