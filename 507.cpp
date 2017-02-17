#include <iostream>
using namespace std;
int T, s, nice[20000+100];
int main(){
    cin>>T;
    for(int r=1; r<=T; r++){
        cin>>s;
        for(int i=1; i<s; i++)
            cin>>nice[i];
        int maxsum, maxlocal, localstartpos=1, localendpos=2, globalstartpos=1, globalendpos=2;
        maxsum=maxlocal=nice[1];
        for(int i=2; i<s; i++){
            if(maxlocal<0){
                maxlocal=nice[i];
                localstartpos=i;
                localendpos=localstartpos+1;
            }else{
                maxlocal+=nice[i];
                localendpos++;
            }
            if(maxlocal>maxsum||((maxlocal==maxsum)&&(localendpos-localstartpos>globalendpos-globalstartpos))){
                maxsum=maxlocal;
                globalstartpos=localstartpos;
                globalendpos=localendpos;
            }
        }
        if(maxsum<0) cout<<"Route "<<r<<" has no nice parts"<<endl;
        else cout<<"The nicest part of route "<<r<<" is between stops "<<globalstartpos<<" and "<<globalendpos<<endl;
    }
    return 0;
}//最大连续和O(n)
