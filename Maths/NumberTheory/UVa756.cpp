#include <iostream>
#include <cstring>
using namespace std;
const int maxn=21252+365+20;
bool t1[maxn], t2[maxn], t3[maxn];
int cs=1;
int main(){
    int p, e, i, d;
    while(cin>>p>>e>>i>>d){
        if(p==-1) break;
        memset(t1, false, sizeof(t1));
        memset(t2, false, sizeof(t2));
        memset(t3, false, sizeof(t3));
        for(int j=p; j>d; j-=23) t1[j]=true;
        for(int j=p; j<maxn; j+=23) t1[j]=true;
        for(int j=e; j>d; j-=28) t2[j]=true;
        for(int j=e; j<maxn; j+=28) t2[j]=true;
        int j=i;
        while(j>d){
            j-=33;
        }
        while(j<=d){
            j+=33;
        }
        while(j<maxn){
            if(t1[j]&&t2[j]){
                cout<<"Case "<<cs++<<": the next triple peak occurs in "<<(j-d)<<" days."<<endl;
                break;
            }
            j+=33;
        }
    }
    return 0;
}
