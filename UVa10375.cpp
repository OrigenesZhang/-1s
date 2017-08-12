#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
long double ln[10010];//double会精度不够
int main(){
    for(int i=1; i<=10000; i++)
        ln[i]=log(i);
    int p, q, r, s;
    cout<<fixed<<setprecision(5);
    while(cin>>p>>q>>r>>s){
        q=min(q, p-q);
        s=min(r, r-s);
        long double num=0;
        for(int i=0; i<q; i++) num+=ln[p-i]-ln[i+1];
        for(int i=0; i<s; i++) num-=ln[r-i]-ln[i+1];
        cout<<exp(num)<<endl;//这个输出在我的电脑上会溢出,可能是编译器的问题
    }
    return 0;
}
//网上也有用唯一分解做的但是比较复杂
