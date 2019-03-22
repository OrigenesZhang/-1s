#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int ans[10], n;
int main(){
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<7; j++)
            if(s.at(j)=='1') ans[j]++;
    }
    int mmax=0;
    for(int i=0; i<7; i++)
        mmax=max(ans[i], mmax);
    cout<<mmax<<endl;
    return 0;
}
