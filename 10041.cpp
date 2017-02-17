#include <iostream>
#include <algorithm>
using namespace std;
int T, r, s[500+10];
int main(){
    cin>>T;
    while(T--){
        cin>>r;
        for(int i=0; i<r; i++)
            cin>>s[i];
        sort(s, s+r);
        long long tot=0;
        int tmp=r/2;
        for(int i=r-1; i>=tmp; i--)
            tot+=s[i]-s[r-1-i];
        cout<<tot<<endl;
    }
    return 0;
}//这题智障
