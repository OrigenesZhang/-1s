#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int N;
int main(){
    while(cin>>N){
        if(!N) break;
        for(int i=0; i<N; i++){
            int tmp;
            cin>>tmp;
            q.push(tmp);
        }
        long long tot=0;
        while(1){
            int a1, a2;
            a1=q.top();
            q.pop();
            a2=q.top();
            q.pop();
            tot+=a1+a2;
            if(q.empty()) break;
            q.push(a1+a2);
        }
        cout<<tot<<endl;
    }
    return 0;
}
