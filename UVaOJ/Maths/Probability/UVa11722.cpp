#include <iostream>
using namespace std;
int T, t1, t2, s1, s2, w;
double s, a;
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>t1>>t2>>s1>>s2>>w;
		a=(t2-t1)*(s2-s1);
		s=0;
		if(t1+w<s2&&t1+w>=s1){
			if(t2+w>=s2) s+=0.5*(s2-t1-w)*(s2-t1-w);
			else s+=0.5*(s2-t2-w+s2-t1-w)*(t2-t1);
		}else if(t1+w>=s2) 1;
		else{
			if(t2+w>s2) s+=0.5*(s2-s1)*(s1-w-t1+s2-w-t1);
			else if(t2+w<=s2&&t2+w>s1) s+=a-0.5*(t2+w-s1)*(t2+w-s1);
			else s+=a;
		}
		if(t2-w<=s1) 1;
		else if(t2-w>s1&&t2-w<=s2){
			if(t1-w<=s1) s+=0.5*(t2-w-s1)*(t2-w-s1);
			else s+=0.5*(t2-t1)*(t2-w-s1+t1-w-s1);
		}else if(t2-w>s2){
			if(t1-w<=s1) s+=0.5*(t2-s1-w+t2-s2-w)*(s2-s1);
			else if(t1-w>s1&&t1-w<s2) s+=a-0.5*(s2-t1+w)*(s2-t1+w);
			else s+=a;
		}
		cout<<"Case #"<<cs<<": "<<(a-s)/a<<endl;
	}
	return 0;
}
