#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct agency{
    string name;
    int a, b, cost;
    inline void input(){
        getline(cin, name, ':');
        cin>>a;
        cin.get();
        cin>>b;
        cin.get();
        cost=0;
    }
    inline void print(){
        cout<<name<<' '<<cost<<endl;
    }
    bool operator < (const agency& b) const{
        if(cost!=b.cost) return cost<b.cost;
        return name<b.name;
    }
}llist[100+10];
int Cases;
agency cost_cal(agency x, int N, int M){
    while(N>M){
        if(N/2>=M){
            if(x.a*(N+1)/2>x.b) x.cost+=x.b;
            else x.cost+=x.a*((N+1)/2);
            N/=2;
        }else{
            x.cost+=x.a*(N-M);
            break;
        }
    }
    return x;
}
int main(){
    cin>>Cases;
    for(int i=1; i<=Cases; i++){
        int N, M, L;
        cin>>N>>M>>L;
        cin.get();
        for(int j=0; j<L; j++){
            llist[j].input();
            llist[j]=cost_cal(llist[j], N, M);
        }
        sort(llist, llist+L);
        cout<<"Case "<<i<<endl;
        for(int j=0; j<L; j++)
            llist[j].print();
    }
    return 0;
}
