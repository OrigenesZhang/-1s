#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn=1234567;
char a[maxn];
set<int> s;
int main(){
    scanf("%s", a+1);
    int n=strlen(a+1);
    s.insert(0); s.insert(n+1);
    for(int i=1; i<=n; i++)
        if(a[i]=='0') s.insert(i);
    for(int i=1; i<=n; i++){
        if(a[i]=='2'){
            auto r=s.lower_bound(i);
            auto l=r;
            l--;
            int p=(*l)+(*r)-i;
            if(*l>0) s.erase(l);
            if(*r<=n) s.erase(r);
            s.insert(p);
        }
    }
    for(int i=1; i<=n; i++) a[i]='1';
    for(auto p:s) a[p]='0';
    for(int i=1; i<=n; i++) printf("%c", a[i]);
    puts("");
    return 0;
}
