//居然人生中又一次用到了基尔霍夫orrrrz
#include <iostream>
using namespace std;
const int maxn=21;
typedef long long ll;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a/gcd(a, b)*b;
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
	fraction operator - (const fraction &rhs) const{
		fraction res;
		res=*this+fraction(-1, 1)*rhs;
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
	fraction operator / (const fraction &rhs) const{
		fraction res;
		res.nom=nom*rhs.den;
		res.den=den*rhs.nom;
		res.simplify();
		return res;
	}
	bool operator == (const fraction &rhs) const{
		return nom*rhs.den==den*rhs.nom;
	}
	bool operator != (const fraction &rhs) const{
		return !(*this==rhs);
	}
};
typedef fraction Matrix[maxn][maxn];
fraction gauss_jordan(Matrix A, int n, int u, int v){
	for(int i=0; i<n; i++){
		int row;
		for(row=i; row<n; row++)
			if(A[row][i]!=fraction(0, 1)) break;
		if(row==n) continue;
		for(int j=0; j<=n; j++) swap(A[i][j], A[row][j]);
		for(int j=n; j>i; j--) A[i][j]=A[i][j]/A[i][i];
		A[i][i]=1;
		for(int j=0; j<n; j++){
			if(i==j) continue;
			if(A[j][i]!=fraction(0, 1)){
				for(int k=n; k>i; k--)
					A[j][k]=A[j][k]-A[j][i]*A[i][k];
				A[j][i]=0;
			}
		}
	}
	return A[u][n]/A[u][u]-A[v][n]/A[v][v];
}
Matrix A, G;
int N, n, m, u, v, p[maxn], Q, HASH[maxn];
ll r;
int Find(int x){
	return x==p[x]?x:p[x]=Find(p[x]);
}
int main(){
	cin>>N;
	for(int cs=1; cs<=N; cs++){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			p[i]=i;
			for(int j=0; j<n; j++)
				G[i][j].reset();
		}
		while(m--){
			cin>>u>>v>>r;
			if(u==v) continue;
			G[u][v]=G[u][v]+fraction(1, r);
			G[v][u]=G[v][u]+fraction(1, r);
			int pu=Find(u), pv=Find(v);
			if(pu!=pv) p[pu]=pv;
		}
		cin>>Q;
		cout<<"Case #"<<cs<<":"<<endl;
		while(Q--){
			cin>>u>>v;
			cout<<"Resistance between "<<u<<" and "<<v<<" is ";
			if(Find(u)!=Find(v)){
				cout<<"1/0"<<endl;
				continue;
			}
			int du, dv, tot=0;
			for(int i=0; i<n; i++){
				if(i==u) du=tot;
				if(i==v) dv=tot;
				if(Find(u)==Find(i)) HASH[tot++]=i;
			}
			tot++;
			for(int i=0; i<tot; i++)
				for(int j=0; j<=tot; j++)
					A[i][j].reset();
			tot--;
			for(int i=0; i<tot; i++){
				for(int j=0; j<tot; j++){
					if(i==j) continue;
					A[i][i]=A[i][i]+G[HASH[i]][HASH[j]];
					A[i][j]=A[i][j]-G[HASH[i]][HASH[j]];
				}
			}
			A[du][tot+1]=1;
			A[dv][tot+1]=-1;
			A[tot][0]=1;
			fraction res=gauss_jordan(A, tot+1, du, dv);
			cout<<res.nom<<'/'<<res.den<<endl;
		}
		cout<<endl;
	}
	return 0;
}
