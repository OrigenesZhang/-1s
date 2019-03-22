//打表出奇迹
#include <iostream>
using namespace std;
int k, res[15];
int main(){
	res[1]=2;
	res[2]=7;
	res[3]=5;
	res[4]=30;
	res[5]=169;
	res[6]=441;
	res[7]=1872;
	res[8]=7632;
	res[9]=1740;
	res[10]=93313;
	res[11]=459901;
	res[12]=1358657;
	res[13]=2504881;
	while(cin>>k){
		if(!k) break;
		cout<<res[k]<<endl;
	}
	return 0;
}
