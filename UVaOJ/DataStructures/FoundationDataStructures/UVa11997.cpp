#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=789;
struct item{
	int sum, index;
	bool operator < (const item& rhs) const{
		return sum>rhs.sum;
	}
};
int num[maxn][maxn], k;
void merge(int* a, int* b, int* c){
	priority_queue<item> q;
	for(int i=0; i<k; i++)
		q.push({a[i]+b[0], 0});
	for(int i=0; i<k; i++){
		item u=q.top();
		q.pop();
		c[i]=u.sum;
		int ind=u.index;
		if(ind+1<k) q.push({c[i]-b[ind]+b[ind+1], ind+1});
	}
}
int main(){
	while(cin>>k){
		for(int i=0; i<k; i++){
			for(int j=0; j<k; j++)
				cin>>num[i][j];
			sort(num[i], num[i]+k);
		}
		for(int i=1; i<k; i++)
			merge(num[0], num[i], num[0]);
		cout<<num[0][0];
		for(int i=1; i<k; i++)
			cout<<' '<<num[0][i];
		cout<<endl;
	}
	return 0;
}
