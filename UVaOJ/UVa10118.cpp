#include <iostream>
#include <cstring>
using namespace std;
int d[45][45][45][45], table[5][45], row[5], n;
int dp(int basket, int candy){//二进制表示篮子里面的状态
    if(d[row[1]][row[2]][row[3]][row[4]]!=-1)
        return d[row[1]][row[2]][row[3]][row[4]];
    int s, cur, tot=0;
    for(int i=1; i<=4; i++){
        s=0;
        row[i]++;
        if(row[i]<=n){
            cur=1<<table[i][row[i]];
            if(cur&basket) s=dp((~cur)&basket, candy-1)+1;
            else if(candy<4) s=dp(cur|basket, candy+1);
        }
        row[i]--;//回溯很重要
        tot=max(tot, s);
    }
    return d[row[1]][row[2]][row[3]][row[4]]=tot;
}
int main(){
    while(cin>>n){
        if(!n) break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=4; j++)
                cin>>table[j][i];
        memset(d, -1, sizeof(d));
        memset(row, 0, sizeof(row));
        cout<<dp(0, 0)<<endl;
    }
    return 0;
}
