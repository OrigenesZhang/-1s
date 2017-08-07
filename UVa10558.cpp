#include <iostream>
#include <cstring>
using namespace std;
int d[110][110], A, N, S, s[110], path[110][110], cnt[110][110], dist[110][110];
bool table[110][110], grid[110][110];
int dp(int i, int a){
    if(d[i][a]!=-1) return d[i][a];
    if(i==100) return d[i][a]=0;
    int num;
    if(!a) return d[i][a]=dist[i][100];
    d[i][a]=0;
    for(int j=i+1; j<100; j++){
        if(100-j<a) break;
        num=dp(j, a-1);
        if(num+dist[i][j]>d[i][a]){
            d[i][a]=num+dist[i][j];
            path[i][a]=j;
        }
    }
    return d[i][a];
}
void print(int i, int a){
    if(!a) return;
    cout<<' '<<path[i][a];
    print(path[i][a], a-1);
}
int main(){
    while(cin>>N){
        if(N==-1) break;
        memset(table, false, sizeof(table));
        memset(grid, false, sizeof(grid));
        memset(d, -1, sizeof(d));
        memset(cnt, 0, sizeof(cnt));
        memset(dist, 0, sizeof(dist));
        for(int i=0; i<N; i++){
            int x, y;
            cin>>x>>y;
            grid[y][x]=true;//样例挺坑的这边WA了一次
        }
        cin>>S;
        for(int i=1; i<=S; i++)
            cin>>s[i];
        cin>>A;
        for(int i=1; i<S; i++){
            for(int j=1; j<100; j++){
                for(int k=s[i]; k<s[i+1]; k++){
                    if(grid[j][k]){
                        table[j][i]=true;
                        break;
                    }
                }
                cnt[j][i]=table[j][i]+cnt[j-1][i];
            }
        }
        for(int i=1; i<100; i++)
            for(int j=i+1; j<=100; j++)
                for(int k=1; k<S; k++)
                    if(cnt[j-1][k]-cnt[i][k]+table[i][k])
                        dist[i][j]++;
        cout<<A<<' '<<1;
        dp(1, A-2);
        print(1, A-2);//递归打印路径神烦
        cout<<' '<<100<<endl;
    }
    return 0;
}
