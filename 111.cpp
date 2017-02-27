//被输入卡成智障orz;从来没见过这么坑的;
/*
对于输入的解释;
e.g. 4 2 3 1;
1在第4位, 2在第2位, 3在第3位, 4在第1位;
*/
#include <iostream>
#include <cstring>
using namespace std;
int mmap[25], seq[25], n, tmp, ans[25][25];
int main(){
    while(cin>>tmp){
        if(cin.get()=='\n'){
            n=tmp;
            for(int i=1; i<=n; i++)
                cin>>mmap[i];
        }else{
            seq[tmp]=mmap[1];
            for(int i=2; i<=n; i++){
                cin>>tmp;
                seq[tmp]=mmap[i];
            }
            memset(ans, 0, sizeof(ans));
            for(int i=1; i<=n; i++){
                ans[seq[i]][seq[i]]=1;
                for(int j=1; j<seq[i]; j++){
                    if(!ans[j][j]) continue;
                    ans[j][seq[i]]=1;
                    for(int k=j; k<seq[i]; k++)
                        if(ans[j][k]) ans[j][seq[i]]=ans[j][seq[i]]<=ans[j][k]?ans[j][seq[i]]=ans[j][k]+1:ans[j][seq[i]];
                }
            }
            int mmax=ans[1][1];
            for(int i=1; i<=n; i++)
                for(int j=i; j<=n; j++)
                    mmax=mmax<ans[i][j]?ans[i][j]:mmax;
            cout<<mmax<<endl;
        }
    }
    return 0;
}
