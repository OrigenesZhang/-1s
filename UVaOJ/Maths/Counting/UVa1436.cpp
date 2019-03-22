//还是老老实实scanf和printf吧
//不知道为什么加了ios_base::sync_with_stdio(false)以后就会RTE虽然没有用cin,cout输入输出多少数据
//这个题的20s一点都不宽裕啊orz (250个点)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int prime[500050], f[500050], tot[500050], cnt[500050], t, n, Pcnt=0;
bool notprime[500050];
long long MOD;
long long fast_pow(long long x, int k){
    long long product=1, base=x;
    while(k){
        if(k&1){
            product*=base;
            product%=MOD;
        }
        base*=base;
        base%=MOD;
        k>>=1;
    }
    return product;
}
void work(int u, int v){
    for(int i=0; i<Pcnt; i++){
        int j=prime[i];
        while(!(u%j)){
            cnt[j]+=v;
            u/=j;
        }
        if(!notprime[u]){
            cnt[u]+=v;
            return;
        }
    }
}
int main(){
    for(int i=2; i<=500000; i++){
        if(notprime[i]) continue;
        prime[Pcnt++]=i;
        for(int j=2*i; j<=500000; j+=i)
            notprime[j]=true;
    }
    scanf("%d", &t);
    while(t--){
        cin>>n>>MOD;
        memset(tot, 0, sizeof(tot));
        f[1]=0;
        for(int i=2; i<=n; i++){
            //cin>>f[i];
            scanf("%d", &f[i]);
            tot[f[i]]++;
        }
        memset(cnt, 0, sizeof(cnt));
        queue<int> q;
        for(int i=1; i<=n; i++)
            if(!tot[i]) q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt[u]++;
            int v=f[u];
            cnt[v]+=cnt[u];
            tot[v]--;
            if(!tot[v]) q.push(v);
        }
        memset(tot, 0, sizeof(tot));
        for(int i=1; i<=n; i++)
            tot[cnt[i]]++;
        memset(cnt, 0, sizeof(cnt));
        for(int i=2; i<=n; i++)
            work(i, 1);
        for(int i=2; i<=n; i++)
            if(tot[i]) work(i, -tot[i]);
        long long res=1;
        for(int i=0; i<Pcnt; i++){
            long long u=prime[i];
            if(cnt[u]) res=(res*fast_pow(u, cnt[u]))%MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
