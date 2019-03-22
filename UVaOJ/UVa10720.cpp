#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
int main(){
    while(cin>>n){
        if(!n) break;
        v.clear();
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        bool flag=true;
        for(int i=n-1; i>=0; i--){
            sort(v.begin(), v.end());
            if(v[i]>i){
                flag=false;
                goto label;
            }
            for(int j=i-1; j>=i-v[i]; j--){
                if(!v[j]){
                    flag=false;
                    goto label;
                }else v[j]--;
            }
        }
        label:
        if(flag) cout<<"Possible"<<endl;
        else cout<<"Not possible"<<endl;
    }
    return 0;
}
