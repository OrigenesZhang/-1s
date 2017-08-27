#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
const string value[13]={"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
const string suit[4]={"Clubs", "Diamonds", "Hearts", "Spades"};
int n, T, cur[53], pre[53], shuffles[100][53];
string tmp;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=52; i++)
            pre[i]=i;
        for(int i=0; i<n; i++)
            for(int j=1; j<=52; j++)
                cin>>shuffles[i][j];
        cin.get();
        while(getline(cin, tmp)){
            if(tmp=="") break;
            stringstream ss(tmp);
            int exec;
            ss>>exec;
            for(int i=1; i<=52; i++)
                cur[i]=pre[shuffles[exec-1][i]];
            memcpy(pre, cur, sizeof(cur));
        }
        for(int i=1; i<=52; i++){
            string s=value[(cur[i]-1)%13]+" of "+suit[(cur[i]-1)/13];
            cout<<s<<endl;
        }
        if(T) cout<<endl;
    }
    return 0;
}
