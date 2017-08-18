#include <iostream>
#include <cstring>
using namespace std;
struct Fib{
    string s;
    int num[250];
    Fib operator+(const Fib& rhs) const{
        Fib c;
        memset(c.num, 0, sizeof(c.num));
        for(int i=1; i<250; i++) c.num[i]=num[i]+rhs.num[i];
        bool change=true;
        while(change){
            change=false;
            if(c.num[1]==2){
                c.num[1]=0;
                c.num[2]++;
                change=true;
            }
            while(c.num[2]>1){
                c.num[3]++;
                c.num[1]++;
                c.num[2]-=2;
                change=true;
            }
            for(int i=2; i<=249; i++){
                while(c.num[i]>1){
                    c.num[i+1]++;
                    c.num[i]-=2;
                    c.num[i-2]++;
                    change=true;
                }
                if(c.num[i]&&c.num[i-1]){
                    c.num[i+1]++;
                    c.num[i]--;
                    c.num[i-1]--;
                    change=true;
                }
            }
        }
        return c;
    }
};
istream &operator>>(istream &in, Fib &fib){
    in>>fib.s;
    int len=fib.s.length();
    memset(fib.num, 0, sizeof(fib.num));
    for(int i=0; i<len; i++)
        fib.num[len-i]=fib.s.at(i)-'0';
    return in;
}
ostream &operator<<(ostream &out, const Fib &fib){
    bool flag=false;
    for(int i=249; i>0; i--){
        if(fib.num[i]>0) flag=true;
        if(flag) out<<fib.num[i];
    }
    if(!flag) out<<0;
    out<<endl;
    return out;
}
int main(){
    Fib f1, f2;
    bool first=true;
    while(cin>>f1>>f2){
        if(!first) cout<<endl;
        first=false;
        f1=f1+f2;
        cout<<f1;
    }
    return 0;
}
