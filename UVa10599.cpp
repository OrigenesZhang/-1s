#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
struct garbage{
    int value, cnt, index;
    inline void init(int i){
        value=1;
        cnt=1;
        index=i;
    }
    bool operator < (const garbage& b) const{
        return index<b.index;
    }
}dp[105*105];
int row, col, cs=1;
stack<int> s;
int main(){
    while(cin>>row>>col){
        if(row==-1&&col==-1) break;
        int x, y, tot=0, mmax=0;
        while(cin>>x>>y){
            if(!(x&&y)) break;
            dp[++tot].init((x-1)*col+y);
        }
        sort(dp+1, dp+tot+1);//1到tot的sort
        for(int i=1; i<=tot; i++){
            for(int j=1; j<i; j++){
                if((dp[j].index%col>dp[i].index%col&&dp[i].index%col>0)||(dp[j].index%col==0&&dp[i].index%col>0)) continue;//特判余数为0的情况
                if(dp[j].value+1>dp[i].value){
                    dp[i].value=dp[j].value+1;
                    dp[i].cnt=dp[j].cnt;
                }else if(dp[j].value+1==dp[i].value)
                    dp[i].cnt+=dp[j].cnt;
            }
            if(dp[i].value>mmax) mmax=dp[i].value;
        }
        cout<<"Case#"<<cs++<<": "<<mmax<<" ";
        int C=0, pos=0;
        for(int i=1; i<=tot; i++){
            if(dp[i].value==mmax){
                C+=dp[i].cnt;
                if(!pos) pos=i;
            }
        }
        cout<<C;
        stack<int> tmp;
        swap(s, tmp);
        bool first=true;
        int prev;
        while(mmax){
            if(dp[pos].value==mmax){
                if(first){
                    s.push(dp[pos].index);
                    mmax--;
                    first=false;
                    prev=dp[pos].index%col;
                    if(!prev) prev=col;
                }else{
                    int rem=dp[pos].index%col;
                    if(!rem) rem=col;
                    if(rem<=prev){//判断能否前推
                        s.push(dp[pos].index);
                        mmax--;
                        prev=rem;
                    }
                }
            }
            pos--;
        }
        while(!s.empty()){
            cout<<' '<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}
