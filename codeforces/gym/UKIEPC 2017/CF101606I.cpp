#include <bits/stdc++.h>
using namespace std;
int N, H[15], T, mmin, rec;
int main(){
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>H[i];
	cin>>T;
	mmin=T%H[0];
	for(int i=1; i<N; i++)
		if(T%H[i]<mmin) mmin=T%H[i], rec=i;
	cout<<H[rec]<<endl;
	return 0;
}
