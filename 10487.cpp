#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt, cs=1;
vector<int> v;
vector<int> s;
int b_search(int q){
    if(q<=s[0]) return 0;
    if(q>=s[cnt-1]) return cnt;
    int l=0, r=cnt-1, m;
    while(r-l>1){
        m=(l+r)/2;
        if(q==s[m]) return m;
        if(q<s[m]) r=m;
        else l=m;
    }
    return r;
}
int main(){
    while(cin>>n){
        if(!n) break;
        cout<<"Case "<<cs++<<":"<<endl;
        v.clear();
        s.clear();
        while(n--){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        int sz=v.size();
        for(int i=0; i<sz; i++)
            for(int j=i+1; j<sz; j++)
                s.push_back(v[i]+v[j]);
        sort(s.begin(), s.end());
        cnt=s.size();
        int m;
        cin>>m;
        while(m--){
            int q;
            cin>>q;
            int out=b_search(q);
            if(out==cnt) out--;
            else out&&(q-s[out-1]<s[out]-q)?out--:1;
            cout<<"Closest sum to "<<q<<" is "<<s[out]<<"."<<endl;
        }
    }
    return 0;
}
