#include <iostream>
using namespace std;
int ca, cb, n;
int main(){
    while(cin>>ca>>cb>>n){
        if(cb==n){
            cout<<"fill B\nsuccess"<<endl;
            continue;
        }
        int i=1;
        while((ca*i)%cb!=n) i++;
        cout<<"fill A\npour A B"<<endl;
        int b=ca;
        for(int j=2; j<=i; j++){
            cout<<"fill A\npour A B"<<endl;
            b+=ca;
            if(b>cb){
                cout<<"empty B\npour A B"<<endl;
                b-=cb;
            }
        }
        cout<<"success"<<endl;
    }
    return 0;
}
