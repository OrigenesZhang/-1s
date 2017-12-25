#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=123456;
int head, Next[maxn], tail;
char s[maxn];
void init(int n){
	for(int i=0; i<n; i++)
		Next[i]=-1;
	head=tail=-1;
}
int main(){
	while(scanf("%s", s)==1){//标准输入输出真心玄学上来不加==1先T两发
		int len=strlen(s), pos=0;
		bool flag=false;
		init(len);
		for(int i=0; i<len; i++){
			if(!flag){
				if(s[i]=='['||s[i]==']') continue;
				head=tail=i;
				pos=i;
				flag=true;
			}else{
				if(s[i]=='[') pos=-1;
				else if(s[i]==']') pos=tail;
				else{
					if(pos==-1){
						Next[i]=head;
						head=i;
						pos=i;
					}else{
						if(Next[pos]==-1){
							tail=i;
							Next[pos]=i;
							pos=i;
						}else{
							int u=Next[pos];
							Next[pos]=i;
							Next[i]=u;
							pos=i;
						}
					}
				}
			}
		}
		for(int i=head; i!=-1; i=Next[i])
			printf("%c", s[i]);
		puts("");
	}
	return 0;
}
