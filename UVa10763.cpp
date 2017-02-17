#include <cstdio>
#include <set>
using namespace std;
struct exchange{
    int loc, dest;
    bool operator < (const exchange& b) const{
        if(loc!=b.loc) return loc<b.loc;
        return dest<b.dest;
    }
};
multiset<exchange> s;
int n;
int main(){
    while(scanf("%d", &n)){
        if(!n) break;
        if(n&1){
            printf("NO\n");
            int tmp;
            for(int i=0; i<2*n; i++) scanf("%d", &tmp);
            continue;
        }
        s.clear();
        for(int i=0; i<n; i++){
            exchange tmp;
            scanf("%d%d", &tmp.loc, &tmp.dest);
            s.insert(tmp);
        }
        multiset<exchange>::iterator it1;
        multiset<exchange>::iterator it2;
        while(!s.empty()){
            it1=s.begin();
            it2=s.find({(*it1).dest, (*it1).loc});
            if(it2!=s.end()&&s.count(*it1)==s.count(*it2)){
                s.erase(it1);
                s.erase(it2);
            }else{
                printf("NO\n");
                goto label;
            }
        }
        printf("YES\n");
        label:;
    }
    return 0;
}
