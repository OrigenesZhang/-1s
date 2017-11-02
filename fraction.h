typedef long long ll;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
}
struct fraction{
	ll nom, den;
	fraction(){
		nom=0;
		den=1;
	}
	fraction(ll a, ll b){
		nom=a;
		den=b;
		simplify();
	}
	inline void reset(){
		nom=0;
		den=1;
	}
	void simplify(){
		ll d=gcd(nom, den);
		nom/=d;
		den/=d;
		if(den<0){
			nom=-nom;
			den=-den;
		}
	}
	inline ll convert(){
		return nom/den;
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
		res.nom=nom*rhs.nom;
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
		res.nom=nom*rhs.den;
		res.den=den*rhs.nom;
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
		return nom*rhs.den==den*rhs.nom;
	}
	bool operator == (const int &rhs) const{
		return nom==den*rhs;
	}
	bool operator != (const fraction &rhs) const{
		return !(*this==rhs);
	}
	bool operator != (const int &rhs) const{
		return !(*this==rhs);
	}
	bool operator < (const fraction &rhs) const{
		return nom*rhs.den<den*rhs.nom;
	}
	bool operator < (const int &rhs) const{
		return nom<den*rhs;
	}
	bool operator > (const fraction &rhs) const{
		return nom*rhs.den>den*rhs.nom;
	}
	bool operator > (const int& rhs) const{
		return nom>den*rhs;
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