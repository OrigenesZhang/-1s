#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;
const int maxn=12345;
const int inf=0x3f3f3f3f;
unordered_map<int, int*> mmap;//这个写矬了
string s;
int inord[maxn], postord[maxn], res, mmin;//一开始看成前序和中序了orz
void build(int* a, int* b, int len, int cur){
	if(!len) return;
	if(len==1){
		if(cur+b[0]<mmin||(cur+b[0]==mmin&&b[0]<res)){
			mmin=cur+b[0];
			res=b[0];
			return;
		}
	}
	if(cur>=mmin) return;
	int* pos=mmap[b[len-1]];
	int lenl=distance(a, pos);
	build(a, b, lenl, cur+b[len-1]);
	build(pos+1, b+lenl, len-lenl-1, cur+b[len-1]);
}
int main(){
	while(getline(cin, s)){
		int len=0;
		mmap.clear();
		stringstream ss(s);
		mmin=inf;
		while(ss>>inord[len]){
			mmap[inord[len]]=&inord[len];
			len++;
		}
		for(int i=0; i<len; i++)
			cin>>postord[i];
		cin.get();
		build(inord, postord, len, 0);
		cout<<res<<endl;
	}
	return 0;
}
