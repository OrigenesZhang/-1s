#include <iostream>
#include <cstring>
using namespace std;
int dp1[550][550], dp2[550][550], n, res;
bool g[550][550];
string s;
int main(){
	while(cin>>n){
		for(int i=1; i<=n; i++){
			cin>>s;
			for(int j=0; j<n; j++)
				g[i][j+1]=(s.at(j)=='x');
		}
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		res=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(g[i][j]){
					int tmp=min(dp1[i-1][j], dp1[i][j-1]);
					dp1[i][j]=tmp+g[i-tmp][j-tmp];
					tmp=min(dp2[i-1][j-1], dp2[i-1][j+1]);
					if(!tmp||!g[i-1][j]) dp2[i][j]=1;
					else if(g[i-2*tmp][j]&&g[i-2*tmp+1][j]) dp2[i][j]=tmp+1;
					else dp2[i][j]=tmp;
					res+=dp1[i][j]+dp2[i][j]-2;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
