#include <iostream>
#include <cstring>
using namespace std;
int n, cs=1;
void exgcd(int a, int b, int& d, int& x, int& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
int inv(int a){
	int d, x, y;
	exgcd(a, n, d, x, y);
	return (x+n)%n;
}
struct Polynomial{
	int deg, coefficient[120];
	Polynomial(){
		deg=0;
		memset(coefficient, 0, sizeof(coefficient));
	}
	inline void update(){
		coefficient[deg]=(coefficient[deg]%n+n)%n;
		while(deg>0&&!coefficient[deg]) deg--;
	}
	Polynomial operator * (const int& rhs){
		Polynomial res=*this;
		for(int i=0; i<=deg; i++)
			res.coefficient[i]=res.coefficient[i]*rhs%n;
		res.update();
		return res;
	}
	Polynomial operator - (const Polynomial& rhs){
		Polynomial res=*this;
		for(int i=0; i<=rhs.deg; i++)
			res.coefficient[deg-i]=(res.coefficient[deg-i]-rhs.coefficient[rhs.deg-i]+n)%n;
		res.update();
		return res;
	}
};
Polynomial mod(Polynomial a, Polynomial b){
	for (int i=a.deg; i>=b.deg; i--){
		int tmp1=a.coefficient[i], tmp2=b.coefficient[b.deg];
		Polynomial tmp=b*inv(tmp2)*tmp1;
		a=a-tmp;
	}
	return a;
}
inline bool check(Polynomial a){
	return a.deg>0||a.coefficient[0];
}
Polynomial pgcd(Polynomial a, Polynomial b){
	return !check(b)?a:pgcd(b, mod(a, b));
}
void print(Polynomial a){
	cout<<a.deg;
	for(int i=a.deg; i>=0; i--)
		cout<<' '<<a.coefficient[i];
	cout<<endl;
}
int main(){
	while(cin>>n){
		if(!n) break;
		Polynomial A, B, res;
		cin>>A.deg;
		for(int i=A.deg; i>=0; i--)
			cin>>A.coefficient[i];
		cin>>B.deg;
		for(int i=B.deg; i>=0; i--)
			cin>>B.coefficient[i];
		cout<<"Case "<<cs++<<": ";
		res=pgcd(A, B);
		print(res*inv(res.coefficient[res.deg]));
	}
	return 0;
}
