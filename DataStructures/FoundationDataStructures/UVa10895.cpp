#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
map<int, vector<pii>> mat;
vector<int> v;
int m, n;
int main(){
	while(cin>>m>>n){
		mat.clear();
		for(int i=1; i<=m; i++){
			int entries;
			cin>>entries;
			v.clear();
			v.push_back(0);
			for(int j=1; j<=entries; j++){
				int r;
				cin>>r;
				v.push_back(r);
			}
			for(int j=1; j<=entries; j++){
				int num;
				cin>>num;
				mat[v[j]].push_back(make_pair(i, num));
			}
		}
		cout<<n<<' '<<m<<endl;
		for(auto it:mat)
			sort(it.second.begin(), it.second.end());
		for(int i=1; i<=n; i++){
			cout<<mat[i].size();
			for(auto it:mat[i]) cout<<' '<<it.first;
			cout<<endl;
			bool flag=false;
			for(auto it:mat[i]){
				if(flag) cout<<' ';
				flag=true;
				cout<<it.second;
			}
			cout<<endl;
		}
	}
	return 0;
}
