#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int N, T, data[100];
bool vis[100][64001];
string res;
inline bool valid(int a){
    return a>=-32000&&a<=32000;
}
bool dfs(int ind, int num, string s){
    if(ind==N){
        if(num==T){
            res=s;
            return true;
        }
        return false;
    }
    if(vis[ind][num+32000])return false;
    vis[ind][num+32000]=true;
    if(valid(num+data[ind])&&dfs(ind+1, num+data[ind], s+'+')) return true;
    if(valid(num-data[ind])&&dfs(ind+1, num-data[ind], s+'-')) return true;
    if(valid(num*data[ind])&&dfs(ind+1, num*data[ind], s+'*')) return true;
    if(data[ind]&&!(num%data[ind])&&valid(num*data[ind])&&dfs(ind+1, num/data[ind], s+'/')) return true;
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&N);
        for(int i=0; i<N; i++)
            scanf("%d",&data[i]);
        scanf("%d",&T);
        memset(vis, false, sizeof(vis));
        if(dfs(1, data[0], "")){
            printf("%d", data[0]);
            for(int i=0; i<res.length(); i++)
                printf("%c%d", res[i], data[i+1]);
            printf("=%d\n", T);
        }
        else printf("NO EXPRESSION\n");
    }
    return 0;
}
