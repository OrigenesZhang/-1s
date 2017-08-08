#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
    while(getline(cin, s)){
        if(s=="#") break;
        int len=s.length();
        long long tot=0;
        for(int i=0; i<len; i++){
            tot<<=8;
            tot+=(int)s.at(i);
            tot%=34943;
        }
        tot<<=16;
        tot%=34943;
        if(!tot){
            cout<<"00 00"<<endl;
        }else{
            int tmp=34943-tot;
            int num[]={0, 0, 0, 0, 0};
            for(int i=1; i<5; i++){
                if(tmp){
                    num[i]=tmp%16;
                    tmp/=16;
                }
            }
            for(int i=4; i>0; i--){
                if(i==2) cout<<' ';
                if(num[i]>=10) cout<<(char)(55+num[i]);
                else cout<<num[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
//一定要吐槽Python,跟zz一样,下面这个写法居然T了
/*
while True:
    s=input()
    if s=="#":
        break
    length=len(s)
    tot=0
    for i in range(0, length):
        tot<<=8
        tot+=ord(s[i])
        tot%=34943
    tot<<=16
    tot%=34943
    if not tot:
        print("00 00")
    else:
        tmp=34943-tot
        num=[0 for i in range(0,5)]
        for i in range(1, 5):
            if tmp:
                num[i]=tmp%16
                tmp//=16
        for i in range(4, 0, -1):
            if i==2:
                print(' ', end="")
            if num[i]>=10:
                print(chr(55+num[i]), end="")
            else:
                print(num[i], end="")
        print()
*/
