//最恶心的输出,真要写分数版了
#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a, b)*b;
}
struct fraction{
	long long nom, den;
	fraction(){
		nom=0;
		den=1;
	}
	fraction(long long a, long long b){
		nom=a;
		den=b;
	}
	void simplify(){
		if(den<0){
			nom=-nom;
			den=-den;
		}
		long long d=gcd(nom, den);
		if(d<0) d=-d;
		nom/=d;
		den/=d;
	}
	fraction& operator = (int rhs){
		(*this).nom=rhs;
		(*this).den=1;
		return *this;
	}
	fraction operator + (const fraction &rhs) const{
		fraction res;
		res.den=lcm(den, rhs.den);
		res.nom=res.den/den*nom+res.den/rhs.den*rhs.nom;
		res.simplify();
		return res;
	}
	fraction operator * (const fraction &rhs) const{
		fraction res;
		res.nom=nom*rhs.nom;
		res.den=den*rhs.den;
		res.simplify();
		return res;
	}
	void print(){
		if(!nom){
			cout<<0<<endl;
			return;
		}
		if(!(nom%den)){
			cout<<nom/den<<endl;
			return;
		}
		int space=0, len=0;
		if(nom/den>0){
			long long INT=nom/den;
			while(INT){
				INT/=10;
				space++;
			}
		}
		if(space) for(int i=0; i<=space; i++) cout<<' ';
		cout<<nom%den<<endl;
		long long DEN=den;
		while(DEN){
			DEN/=10;
			len++;
		}
		cout<<nom/den<<' ';
		for(int i=0; i<len; i++) cout<<'-';
		cout<<endl;
		for(int i=0; i<=space; i++) cout<<' ';
		cout<<den<<endl;
	}
}dp[40][40];
int n;
int main(){
	for(long long i=1; i<=33; i++){
		dp[i][0]=0;
		for(long long j=1; j<=i; j++)
			dp[i][j]=(dp[i][j-1]*fraction(j, i)+fraction(1, 1))*fraction(i, j);
	}
	while(cin>>n) dp[n][n].print();
	return 0;
}
