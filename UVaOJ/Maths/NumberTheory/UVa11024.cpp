#include <iostream>
using namespace std;
int T, s[3][3], p[3][3], S, P;
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
int main(){
	cin>>T;
	while(T--){
		for(int i=1; i<=2; i++){
			for(int j=1; j<=2; j++)
				cin>>s[i][j];
			for(int j=1; j<=2; j++)
				cin>>p[i][j];
		}
		P=p[1][1];
		for(int i=1; i<=2; i++)
			for(int j=1; j<=2; j++)
				P=gcd(P, p[i][j]);
		S=0;
		for(int i=1; i<=2; i++){
			for(int j=1; j<=2; j++){
				if(i==j) S-=P-s[i][j];
				else S+=P-s[i][j];
			}
		}
		cout<<(S%P?"No":"Yes")<<endl;
	}
	return 0;
}
