#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double combination[50050], num[50050], res;
int pw, N, n;
int main(){
    cin>>N;
    cout<<fixed<<setprecision(3);
    for(int cs=1; cs<=N; cs++){
        cin>>n;
        for(int i=0; i<n; i++) cin>>num[i];
        if(n==1){
            cout<<"Case #"<<cs<<": "<<num[0]<<endl;
            continue;
        }
        combination[0]=1;
        pw=n-1;
        res=combination[0]*num[0]/pow(2, pw);
        for(int i=1; i<n; i++){
            combination[i]=combination[i-1]*(n-i)/i;//不能用 pw (会变)
            if(combination[i]>1024&&pw>=10){
                combination[i]/=1024;
                pw-=10;
            }
            res+=num[i]*combination[i]/pow(2, pw);
        }
        cout<<"Case #"<<cs<<": "<<res<<endl;
    }
    return 0;
}
