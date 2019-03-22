#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
string s;
double v;
int cur, len, seg;
void eval(){
	while(s.at(cur)==' ') cur++;
	if(s.at(cur)=='('){
		seg=0;
		cur++;
	}else if(s.at(cur)==')'){
		seg=1;
		cur++;
	}else if(isdigit(s.at(cur))||s.at(cur)=='.'||s.at(cur)=='-'){
		int sign=1;
		if(s.at(cur)=='-'){
			sign=-1;
			cur++;
		}
		v=0;
		seg=2;
		while(cur<len&&isdigit(s.at(cur)))
			v=v*10+s.at(cur++)-'0';
		if(cur<len&&s.at(cur)=='.'){
			cur++;
			double den=10;
			while(cur<len&&isdigit(s.at(cur))){
				v+=(s.at(cur++)-'0')/den;
				den*=10;
			}
		}
		v*=sign;
	}
}
double read(){
	eval();
	if(!seg){
		eval();
		double p=v;
		double x=read();
		double y=read();
		eval();
		return p*(x+y)+(1-p)*(x-y);
	}
	return v;
}
int main(){
	cout<<fixed<<setprecision(2);
	while(getline(cin, s)){
		if(s=="()") break;
		cur=0;
		len=s.length();
		cout<<read()<<endl;
	}
	return 0;
}
