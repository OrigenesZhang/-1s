#include <iostream>
using namespace std;
int a[7];
int main(){
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
        if(!(a[1]||a[2]||a[3]||a[4]||a[5]||a[6])) break;
        int cnt=a[6];
        if(a[1]>11*a[5]) a[1]-=11*a[5];
        else a[1]=0;
        cnt+=a[5];
        if(a[2]>5*a[4]) a[2]-=5*a[4];
        else{
            if(a[1]){
                if(4*(5*a[4]-a[2])>a[1]) a[1]=0;
                else a[1]-=4*(5*a[4]-a[2]);
            }
            a[2]=0;
        }
        cnt+=a[4];
        if(!(a[3]%4)) cnt+=a[3]/4;
        else{
            cnt+=a[3]/4+1;
            if(a[3]%4==1){
                if(a[2]>5){
                    if(a[1]>7) a[1]-=7;
                    else a[1]=0;
                    a[2]-=5;
                }else{
                    if(a[1]>27-4*a[2]) a[1]-=27-4*a[2];
                    else a[1]=0;
                    a[2]=0;
                }
            }else if(a[3]%4==2){
                if(a[2]>3){
                    if(a[1]>6) a[1]-=6;
                    else a[1]=0;
                    a[2]-=3;
                }else{
                    if(a[1]>18-4*a[2]) a[1]-=18-4*a[2];
                    else a[1]=0;
                    a[2]=0;
                }
            }else{
                if(a[2]){
                    if(a[1]>5) a[1]-=5;
                    else a[1]=0;
                    a[2]--;
                }else{
                    if(a[1]>9) a[1]-=9;
                    else a[1]=0;
                }
            }
        }
        if(!(a[2]%9)) cnt+=a[2]/9;
        else{
            cnt+=a[2]/9+1;
            if(a[1]>36-4*(a[2]%9)) a[1]-=36-4*(a[2]%9);//运算优先级
            else a[1]=0;
        }
        cnt+=a[1]/36+(a[1]%36>0);
        cout<<cnt<<endl;
    }
    return 0;
}
