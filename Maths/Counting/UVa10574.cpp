#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> Point;
typedef pair<int, int> Edge;
Point p[5050];
Edge e[5050*5050];
int t, n, tot;
long long cnt, res;
int main(){
	cin>>t;
	for(int cs=1; cs<=t; cs++){
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>p[i].first>>p[i].second;
		sort(p, p+n);
		tot=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(p[i].first!=p[j].first) break;
				e[tot++]=make_pair(p[i].second, p[j].second);
			}
		}
		sort(e, e+tot);
		cnt=1;
		res=0;
		for(int i=1; i<tot; i++){
			if(e[i]==e[i-1]) cnt++;
			else{
				res+=cnt*(cnt-1)/2;
				cnt=1;
			}
		}
		res+=cnt*(cnt-1)/2;
		cout<<"Case "<<cs<<": "<<res<<endl;
	}
	return 0;
}
