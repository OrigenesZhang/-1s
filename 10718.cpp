#include <iostream>
#include <cstring>
using namespace std;
void dtob(long long d, bool* b){
    int cur=0;
    while(d){
        b[cur++]=d%2;
        d>>=1;
    }
}
int main(){
    long long N, L, U;
    while(cin>>N>>L>>U){
        bool n[64], l[64], u[64], m[64];
        memset(n, false, sizeof(n));
        memset(l, false, sizeof(l));
        memset(u, false, sizeof(u));
        dtob(N, n);
        dtob(L, l);
        dtob(U, u);
        int i;
        for(i=63; i>=0; i--){
            if(l[i]==u[i]) m[i]=l[i];
            else break;
        }
        if(n[i]) m[i]=false;
        else m[i]=true;
        if(m[i]){
            bool sign=false;
            for(int j=i-1; j>=0; j--){
                if(sign) m[j]=!n[j];
                else if(u[j]){
                    if(n[j]){
                        sign=true;
                        m[j]=false;
                    }else m[j]=true;
                }else m[j]=false;
            }
        }else{
            bool sign=false;
            for(int j=i-1; j>=0; j--){
                if(sign) m[j]=!n[j];
                else if(!l[j]){
                    if(!n[j]){
                        sign=true;
                        m[j]=true;
                    }else m[j]=false;
                }else m[j]=true;
            }
        }
        long long M=0;
        for(i=63; i>=0; i--){
            M<<=1;
            M+=m[i];
        }
        cout<<M<<endl;
    }
    return 0;
}
