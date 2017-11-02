typedef long long ll;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
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
	fraction& operator = (int rhs){
		(*this).num=rhs;
		(*this).den=1;
		return *this;
	}
	fraction operator + (const fraction &rhs) const{
		fraction res;
		res.den=lcm(den, rhs.den);
		res.num=res.den/den*num+res.den/rhs.den*rhs.num;
		res.simplify();
		return res;
	}
	fraction operator += (const fraction &rhs){
		return *this=*this+rhs;
	}
	fraction operator + (const int &rhs) const{
		fraction r(rhs, 1);
		return *this+r;
	}
	fraction operator += (const int &rhs){
		return *this=*this+rhs;
	}
	fraction operator - (const fraction &rhs) const{
		fraction res;
		res=*this+fraction(-1, 1)*rhs;
		res.simplify();
		return res;
	}
	fraction operator -= (const fraction &rhs){
		return *this=*this-rhs;
	}
	fraction operator - (const int &rhs) const{
		fraction r(rhs, 1);
		return *this-r;
	}
	fraction operator -= (const int &rhs){
		return *this=*this-rhs;
	}
	fraction operator * (const fraction &rhs) const{
		fraction res;
		res.num=num*rhs.num;
		res.den=den*rhs.den;
		res.simplify();
		return res;
	}
	fraction operator *= (const fraction &rhs){
		return *this=(*this)*rhs;
	}
	fraction operator * (const int &rhs) const{
		fraction r(rhs, 1);
		return (*this)*r;
	}
	fraction operator *= (const int &rhs){
		return *this=(*this)*rhs;
	}
	fraction operator / (const fraction &rhs) const{
		fraction res;
		res.num=num*rhs.den;
		res.den=den*rhs.num;
		res.simplify();
		return res;
	}
	fraction operator /= (const fraction &rhs){
		return *this=(*this)/rhs;
	}
	fraction operator / (const int &rhs) const{
		fraction r(rhs, 1);
		return (*this)/r;
	}
	fraction operator /= (const int &rhs){
		return *this=(*this)/rhs;
	}
	bool operator == (const fraction &rhs) const{
		return num*rhs.den==den*rhs.num;
	}
	bool operator == (const int &rhs) const{
		return num==den*rhs;
	}
	bool operator != (const fraction &rhs) const{
		return !(*this==rhs);
	}
	bool operator != (const int &rhs) const{
		return !(*this==rhs);
	}
	bool operator < (const fraction &rhs) const{
		return num*rhs.den<den*rhs.num;
	}
	bool operator < (const int &rhs) const{
		return num<den*rhs;
	}
	bool operator > (const fraction &rhs) const{
		return num*rhs.den>den*rhs.num;
	}
	bool operator > (const int& rhs) const{
		return num>den*rhs;
	}
	bool operator <= (const fraction &rhs) const{
		return *this==rhs||*this<rhs;
	}
	bool operator <= (const int& rhs) const{
		return *this==rhs||*this<rhs;
	}
	bool operator >= (const fraction &rhs) const{
		return *this>rhs||*this==rhs;
	}
	bool operator >= (const int &rhs) const{
		return *this>rhs||*this==rhs;
	}
};