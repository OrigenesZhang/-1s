#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> ans;
int n;
int main(){
    cin>>n;
    cout<<n<<':'<<endl;
    for(int k=2; k<n; k++){
        if((n+k-1)%(2*k-1)==0) cout<<k<<','<<k-1<<endl;
        else if(n%(2*k-1)==0) cout<<k<<','<<k-1<<endl;
        if(n%k==0) cout<<k<<','<<k<<endl;
    }
    return 0;
}
