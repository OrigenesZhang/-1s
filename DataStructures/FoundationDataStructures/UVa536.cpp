#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=35;
stack<char> s;
char preord[maxn], inord[maxn];
void build(char* s1, char* s2, int len){
	if(!len) return;
	if(len==1){
		s.push(s1[0]);
		return;
	}
	for(int i=0; i<len; i++){
		if(s2[i]==s1[0]){
			s.push(s2[i]);
			int lenl=i, lenr=len-i-1;
			build(s1+lenl+1, s2+i+1, lenr);
			build(s1+1, s2, lenl);
			return;
		}
	}
}
int main(){
	while(scanf("%s %s", preord, inord)==2){
		int len=strlen(preord);
		build(preord, inord, len);
		while(!s.empty()){
			printf("%c", s.top());
			s.pop();
		}
		puts("");
	}
	return 0;
}
