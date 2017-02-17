#include <iostream>
#include <vector>
using namespace std;
long long num[15];
bool op[15];
vector<long long> mul, add;
int main(){
    int N;
    cin>>N;
    while(N--){
        int cnt=0;
        while(1){
            cin>>num[cnt];
            char c=cin.get();
            if(c=='\n') break;
            else if(c=='+') op[cnt++]=true;
            else op[cnt++]=false;
        }
        mul.clear();
        long long tmp=num[0];
        for(int i=0; i<cnt; i++){
            if(op[i]) tmp+=num[i+1];
            else{
                mul.push_back(tmp);
                tmp=num[i+1];
            }
        }
        mul.push_back(tmp);
        add.clear();
        tmp=num[0];
        for(int i=0; i<cnt; i++){
            if(op[i]){
                add.push_back(tmp);
                tmp=num[i+1];
            }else tmp*=num[i+1];
        }
        add.push_back(tmp);
        long long mmax=mul[0], mmin=add[0];
        for(int i=1; i<mul.size(); i++)
            mmax*=mul[i];
        for(int i=1; i<add.size(); i++)
            mmin+=add[i];
        cout<<"The maximum and minimum are "<<mmax<<" and "<<mmin<<"."<<endl;
    }
    return 0;
}
