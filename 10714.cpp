#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main(){
    cin>>t;
    while(t--){
        int n, l, mmax, mmin, tmp;
        cin>>l>>n;
        cin>>tmp;
        mmax=max(tmp, l-tmp);
        mmin=min(tmp, l-tmp);
        for(int i=1; i<n; i++){
            cin>>tmp;
            mmax=max(max(tmp, l-tmp), mmax);
            mmin=max(min(tmp, l-tmp), mmin);
        }
        cout<<mmin<<' '<<mmax<<endl;
    }
    return 0;
}
