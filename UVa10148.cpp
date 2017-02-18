#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T, N, K, l, r;
    cin>>T;
    while(T--){
        cin>>K>>N;
        vector<pair<int, int>> v;
        for(int i=0; i<N; i++){
            cin>>l>>r;
            if(l>r)	swap(l, r);
            v.push_back(make_pair(r, l));
        }
        sort(v.begin(), v.end());
        bool state[20050]={};
        int tot=0;
        for(int i=0; i<N; i++){
            int cnt=0, l=v[i].second, r=v[i].first;
            for(int j=l; j<=r; j++)
                cnt+=state[j+10000];
            for(int j=r; j>=l&&cnt<K; j--){
                if(!state[j+10000]){
                    cnt++;
                    state[j+10000]=1;
                    tot++;
                }
            }
        }
        cout<<tot<<endl;
        for(int i=0; i<20050; i++)
            if(state[i]) cout<<i-10000<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
