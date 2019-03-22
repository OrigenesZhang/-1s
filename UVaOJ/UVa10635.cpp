#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int mmap[70000], t;
vector<int> dp;
int main(){
    cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n, p, q;
        cin>>n>>p>>q;
        p++;
        q++;
        memset(mmap, 0, sizeof(mmap));
        for(int i=1; i<=p; i++){
            int tmp;
            cin>>tmp;
            mmap[tmp]=i;
        }
        dp.clear();
        dp.push_back(0);
        for(int i=1; i<=q; i++){
            int tmp;
            cin>>tmp;
            tmp=mmap[tmp];//Hash
            if(tmp>dp.back()) dp.push_back(tmp);
            else{
                int pos=lower_bound(dp.begin(), dp.end(), tmp)-dp.begin();//LIS bsearch
                dp[pos]=tmp;
            }
        }
        cout<<"Case "<<cs<<": "<<dp.size()-1<<endl;
    }
    return 0;
}
