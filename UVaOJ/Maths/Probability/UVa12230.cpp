#include <iostream>
#include <iomanip>
using namespace std;
int n, D, cs=1;
double p, L, v, d;
int main(){
	cout<<fixed<<setprecision(3);
	while(cin>>n>>D){
		if(!n&&!D) break;
		d=D;
		while(n--){
			cin>>p>>L>>v;
			d=d-L+2*L/v;
		}
		cout<<"Case "<<cs++<<": "<<d<<'\n'<<endl;
	}
	return 0;
}
