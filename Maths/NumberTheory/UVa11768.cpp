#include <iostream>
#include <cmath>
using namespace std;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
int N, X1, Y1, X2, Y2;
double u1, v1, u2, v2;
int main(){
	cin>>N;
	while(N--){
		cin>>u1>>v1>>u2>>v2;
		X1=u1*10;
		Y1=v1*10;
		X2=u2*10;
		Y2=v2*10;
		if(X1==X2){
			if(X1%10) cout<<0<<endl;
			else
				cout<<max((int)floor(max(v1, v2)-(int)ceil(min(v1, v2))+1), 0)<<endl;
			continue;
		}
		if(Y1==Y2){
			if(Y1%10) cout<<0<<endl;
			else{
				if(u1>u2) swap(u1, u2);
				cout<<max((int)floor(u2)-(int)ceil(u1)+1, 0)<<endl;
			}
			continue;
		}
		long long a=(Y2-Y1)*10, b=(X1-X2)*10, c=(long long)X1*Y2-(long long)Y1*X2, x, y, d, cnt=0;
		if(u1>u2) swap(u1, u2);
		X1=ceil(u1);
		X2=floor(u2);
		if(X1>X2){
			cout<<0<<endl;
			continue;
		}
		exgcd(a, b, d, x, y);
		if(c%d){
			cout<<0<<endl;
			continue;
		}
		b/=d;
		x*=c/d;
		y*=c/d;
		if(b<0) b=-b;
		x=x-(x-X1)/b*b;
		x-=b;
		while(x<X1) x+=b;
		while(x+cnt*b<=X2) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
