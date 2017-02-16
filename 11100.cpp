#include <iostream>
#include <algorithm>
using namespace std;
int n, a[10000+100];
int main(){
    while(cin>>n){
        if(!n) break;
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a, a+n);
        int tot=0, tmp=1;
        for(int i=1; i<n; i++){
            if(a[i]==a[i-1]) tmp++;
            else{
                tot=max(tot, tmp);
                tmp=1;
            }
        }
        tot=max(tot, tmp);
        cout<<tot<<endl;
        for(int i=0; i<tot; i++){
            bool isfirst=true;
            for(int j=i; j<n; j+=tot){
                if(!isfirst) cout<<' ';
                cout<<a[j];
                isfirst=false;
            }
            cout<<endl;
        }
    }
    return 0;
}
