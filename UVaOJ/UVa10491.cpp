#include <iostream>
#include <iomanip>
using namespace std;
double ncow, ncar, nshow;
int main(){
    cout<<fixed<<setprecision(5);
    while(cin>>ncow>>ncar>>nshow)
        cout<<ncow*ncar/(ncow+ncar)/(ncow+ncar-nshow-1)+ncar*(ncar-1)/(ncow+ncar)/(ncow+ncar-nshow-1)<<endl;
    return 0;
}
