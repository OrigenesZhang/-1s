#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
const string table[]={"id", "id-", "rot", "rot-", "sym", "sym-", "bhsym", "bhsym-", "bvsym", "bvsym-", "div", "div-", "mix", "mix-"};
const int maxn=(1<<10)+1;
int n, img[maxn][maxn], buff[maxn][maxn], tot, state[maxn], T;
long long res, cnt;
string str, cur;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a, b)*b;
}
inline int indexing(string s){
	for(int i=0; i<14; i++)
		if(s==table[i]) return i;
}
void rot(bool flag){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			flag?buff[i][j]=img[n-1-j][i]:buff[n-1-j][i]=img[i][j];
	memcpy(img, buff, sizeof(buff));
}
void sym(){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			buff[i][j]=img[i][n-1-j];
	memcpy(img, buff, sizeof(buff));
}
void bhsym(){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			buff[i][j]=i>=n>>1?img[i][n-1-j]:img[i][j];
	memcpy(img, buff, sizeof(buff));
}
void bvsym(){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			buff[i][j]=i>=n>>1?img[3*n/2-i-1][j]:img[i][j];
	memcpy(img, buff, sizeof(buff));
}
void div(bool flag){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			flag?(i&1?buff[i/2+n/2][j]=img[i][j]:buff[i/2][j]=img[i][j]):(buff[i][j]=i&1?img[i/2+n/2][j]:img[i/2][j]);
	memcpy(img, buff, sizeof(buff));
}
void mix(bool flag){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i&1) flag?(buff[i][j]=j&1?img[i][n/2+j/2]:img[i-1][n/2+j/2]):(j&1?buff[i][i/2+j/2]=img[i][j]:buff[i-1][n/2+j/2]=img[i][j]);
			else flag?(buff[i][j]=j&1?img[i+1][j>>1]:img[i][j>>1]):(j&1?buff[i+1][j>>1]=img[i][j]:buff[i][j>>1]=img[i][j]);
		}
	}
	memcpy(img, buff, sizeof(buff));
}
void process(){
	for(int i=tot-1; i>=0; i--){
		switch(state[i]){
			case 2:{
				rot(true);
				break;
			}
			case 3:{
				rot(false);
				break;
			}
			case 4:{
				sym();
				break;
			}
			case 5:{
				sym();
				break;
			}
			case 6:{
				bhsym();
				break;
			}
			case 7:{
				bhsym();
				break;
			}
			case 8:{
				bvsym();
				break;
			}
			case 9:{
				bvsym();
				break;
			}
			case 10:{
				div(true);
				break;
			}
			case 11:{
				div(false);
				break;
			}
			case 12:{
				mix(true);
				break;
			}
			case 13:{
				mix(false);
				break;
			}
			default: break;
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin.get();
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				img[i][j]=i*n+j;
		getline(cin, str);
		stringstream ss(str);
		tot=0;
		while(ss>>cur)
			state[tot++]=indexing(cur);
		process();
		res=1;
		memset(buff, 0, sizeof(buff));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(buff[i][j]) continue;
				int x=img[i][j]/n, y=img[i][j]%n;
				cnt=0;
				while(!buff[x][y]){
					buff[x][y]=1;
					cnt++;
					int tmp=img[x][y];
					x=tmp/n;
					y=tmp%n;
				}
				res=lcm(res, cnt);
			}
		}
		cout<<res<<endl;
		if(T) cout<<endl;
	}
	return 0;
}
