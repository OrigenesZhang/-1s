#include <iostream>
#include <cstring>
using namespace std;
int N, A, B, MOD, tot, num[40], d[15][120][2][2][2];
int dp(int digit, int pos, bool smaller, bool ss, bool prezero){
    int& res=d[digit][pos][smaller][ss][prezero];
    if(res!=-1) return res;
    res=0;
    if(digit==tot)
        return res=ss;
    if(!prezero){
        if(digit+1==tot&&!N) res+=dp(digit+1, 0, true, true, true);
        else res+=dp(digit+1, 0, true, false, false);
        for(int i=1; i<=(smaller?9:num[digit]); i++){
            bool fs=smaller, fss=ss;
            if(i<num[digit]) fs=true;
            if(pos*10+i==N) fss=true;
            res+=dp(digit+1, (pos*10+i)%MOD, fs, fss, true);
        }
        return res;
    }
    if(ss){
        for(int i=0; i<=(smaller?9:num[digit]); i++){
            bool fs=smaller;
            if(i<num[digit]) fs=true;
            res+=dp(digit+1, (pos*10+i)%MOD, fs, ss, prezero);
        }
        return res;
    }
    for(int i=0; i<=(smaller?9:num[digit]); i++){
        bool fs=smaller, fss=ss;
        if(i<num[digit]) fs=true;
        if(pos*10+i==N) fss=true;
        res+=dp(digit+1, (pos*10+i)%MOD, fs, fss, prezero);
    }
    return res;
}
int solve(int cur){
    if(!cur&&!N) return 1;
    if(cur<1) return 0;
    tot=0;
    int tmp=cur;
    while(tmp){
        num[tot++]=tmp%10;
        tmp/=10;
    }
    for(int i=0; i<(tot>>1); i++)
        swap(num[i], num[tot-i-1]);
    memset(d, -1, sizeof(d));
    return dp(0, 0, false, false, false);
}
int main(){
    while(cin>>A>>B>>N){
        if(A==-1&&B==-1&&N==-1) break;
        MOD=100;
        if(N<100) MOD=10;
        if(N<10) MOD=1;
        cout<<solve(B)-solve(A-1)<<endl;
    }
    return 0;
}
