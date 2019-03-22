#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
int T, W, N, mmap[105][105];
int main(){
    cin>>T;
    while(T--){
        cin>>W>>N;
        memset(mmap, -1, sizeof(mmap));
        for(int i=0; i<W; i++){
            int cur, tmp;
            cin>>cur;
            string s;
            getline(cin, s);
            stringstream sin(s);
            while(sin>>tmp) mmap[cur][tmp]=0;
        }
        bool flag=true;
        for(int i=1; i<=W; i++){
            if(mmap[i][1]<0&&flag) mmap[i][1]=1;
            else if(mmap[i][1]==0) flag=false;
            else mmap[i][1]=0;
        }
        flag=true;
        for(int i=2; i<=N; i++){
            if(mmap[1][i]<0&&flag) mmap[1][i]=1;
            else if(mmap[1][i]==0) flag=false;
            else mmap[1][i]=0;
        }
        for(int i=2; i<=W; i++)
            for(int j=2; j<=N; j++)
                if(mmap[i][j]<0) mmap[i][j]=mmap[i-1][j]+mmap[i][j-1];
        cout<<mmap[W][N]<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
//首先吐槽一下这道I/O比题难的题;
//其次这道题I/O的难点在于行末可能有空格所以不能直接写while(cin.get()!='\n');
//字符串流是个好东西233;
