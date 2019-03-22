#include <iostream>
#include <algorithm>
#include <set>
typedef long long ll;
//高精度分数
namespace Fraction{
	ll gcd(ll a, ll b){
		return !b?a:gcd(b, a%b);
	}
	ll lcm(ll a, ll b){
		return b/gcd(a, b)*a;
	}
	struct fraction{
		ll num, den;
		fraction(){
			num=0;
			den=1;
		}
		fraction(ll a, ll b){
			num=a;
			den=b;
			simplify();
		}
		inline void read(){
			std::cin>>num>>den;
			simplify();
		}
		inline void reset(){
			num=0;
			den=1;
		}
		void simplify(){
			ll d=gcd(num, den);
			num/=d;
			den/=d;
			if(den<0){
				num=-num;
				den=-den;
			}
		}
		inline ll convert(){
			return num/den;
		}
		fraction& operator=(int rhs){
			(*this).num=rhs;
			(*this).den=1;
			return *this;
		}
		fraction operator+(const fraction& rhs) const{
			fraction res;
			res.den=lcm(den, rhs.den);
			res.num=res.den/den*num+res.den/rhs.den*rhs.num;
			res.simplify();
			return res;
		}
		fraction operator+=(const fraction& rhs){
			return *this=*this+rhs;
		}
		fraction operator+(const int& rhs) const{
			fraction r(rhs, 1);
			return *this+r;
		}
		fraction operator+=(const int& rhs){
			return *this=*this+rhs;
		}
		fraction operator-(const fraction& rhs) const{
			fraction res;
			res=*this+fraction(-1, 1)*rhs;
			res.simplify();
			return res;
		}
		fraction operator-=(const fraction& rhs){
			return *this=*this-rhs;
		}
		fraction operator-(const int& rhs) const{
			fraction r(rhs, 1);
			return *this-r;
		}
		fraction operator-=(const int& rhs){
			return *this=*this-rhs;
		}
		fraction operator*(const fraction& rhs) const{
			fraction res;
			res.num=num*rhs.num;
			res.den=den*rhs.den;
			res.simplify();
			return res;
		}
		fraction operator*=(const fraction& rhs){
			return *this=(*this)*rhs;
		}
		fraction operator*(const int& rhs) const{
			fraction r(rhs, 1);
			return (*this)*r;
		}
		fraction operator*=(const int& rhs){
			return *this=(*this)*rhs;
		}
		fraction operator/(const fraction& rhs) const{
			fraction res;
			res.num=num*rhs.den;
			res.den=den*rhs.num;
			res.simplify();
			return res;
		}
		fraction operator/=(const fraction& rhs){
			return *this=(*this)/rhs;
		}
		fraction operator/(const int& rhs) const{
			fraction r(rhs, 1);
			return (*this)/r;
		}
		fraction operator/=(const int& rhs){
			return *this=(*this)/rhs;
		}
		bool operator==(const fraction& rhs) const{
			return num*rhs.den==den*rhs.num;
		}
		bool operator==(const int& rhs) const{
			return num==den*rhs;
		}
		bool operator!=(const fraction& rhs) const{
			return !(*this==rhs);
		}
		bool operator!=(const int& rhs) const{
			return !(*this==rhs);
		}
		bool operator<(const fraction& rhs) const{
			return num*rhs.den<den*rhs.num;
		}
		bool operator<(const int& rhs) const{
			return num<den*rhs;
		}
		bool operator>(const fraction& rhs) const{
			return num*rhs.den>den*rhs.num;
		}
		bool operator>(const int& rhs) const{
			return num>den*rhs;
		}
		bool operator<=(const fraction& rhs) const{
			return *this==rhs||*this<rhs;
		}
		bool operator<=(const int& rhs) const{
			return *this==rhs||*this<rhs;
		}
		bool operator>=(const fraction& rhs) const{
			return *this>rhs||*this==rhs;
		}
		bool operator>=(const int& rhs) const{
			return *this>rhs||*this==rhs;
		}
	};
	struct Point{
		fraction x, y;
		Point(fraction x={0, 1}, fraction y={1, 1}): x(x), y(y){}
		inline void read(){
			ll xx, yy;
			std::cin>>xx>>yy;
			*this={{xx, 1}, {yy, 1}};
		}
		Point operator + (const Point& rhs){
			return {x+rhs.x, y+rhs.y};
		}
		Point operator - (const Point& rhs){
			return {x-rhs.x, y-rhs.y};
		}
		Point operator * (const int& rhs){
			return {x*rhs, y*rhs};
		}
		Point operator / (const int& rhs){
			return {x/rhs, y/rhs};
		}
		bool operator == (const Point& rhs) const{
			return x==rhs.x&&y==rhs.y;
		}
		bool operator < (const Point& rhs) const{
			return x<rhs.x||(x==rhs.x&&y<rhs.y);
		}
	};
}

using namespace std;
const int maxn=12345;
int c, n;
Fraction::Point pts[maxn];
set<Fraction::Point> s;
void solve(int p, Fraction::Point& centre){
	for(int i=0; i<p; i++){
		Fraction::Point cur=pts[i]+(centre-pts[i])*2;
		if(s.find(cur)!=s.end()) s.erase(cur);
		else{
			cout<<"no"<<endl;
			return;
		}
	}
	cout<<"yes"<<endl;
}
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		for(int i=0; i<n; i++) pts[i].read();
		sort(pts, pts+n);
		if(n<=2){
			cout<<"yes"<<endl;
			continue;
		}
		s.clear();
		for(int i=0; i<n; i++)
			s.insert(pts[i]);
		Fraction::Point centre;
		if(n&1) centre=pts[n>>1];
		else centre=(pts[n-1>>1]+pts[n>>1])/2;
		solve(n>>1, centre);
	}
	return 0;
}
