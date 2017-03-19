#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int table[10005], dp1[10005], dp2[10005], N, mmax;
vector<int> v;
int main(){
    while(cin>>N){
        for(int i=0; i<N; i++)
            cin>>table[i];
        v.clear();
        v.push_back(table[0]);
        dp1[0]=1;
        for(int i=1; i<N; i++){
            if(table[i]>v.back()){
                v.push_back(table[i]);
                dp1[i]=v.size();
            }else{
                int pos=lower_bound(v.begin(), v.end(), table[i])-v.begin();//动规必须二分不然会T
                v[pos]=table[i];
                dp1[i]=pos+1;
            }
        }
        v.clear();
        v.push_back(table[N-1]);
        dp2[N-1]=1;
        for(int i=N-2; i>=0; i--){
            if(table[i]>v.back()){
                v.push_back(table[i]);
                dp2[i]=v.size();
            }else{
                int pos=lower_bound(v.begin(), v.end(), table[i])-v.begin();
                v[pos]=table[i];
                dp2[i]=pos+1;
            }
        }
        mmax=1;
        for(int i=0; i<N; i++)
            mmax=max(min(dp1[i], dp2[i]), mmax);
        cout<<2*mmax-1<<endl;
    }
    return 0;
}
