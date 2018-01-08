//区间修改[两种tag] 区间查询
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e6+5;
const int maxlen=1<<20;
int minv[4*maxn], maxv[4*maxn], sumv[4*maxn], setv[4*maxn], addv[4*maxn];
int r, c, m, op, _min, _max, _sum, a, b;
void init(){
	memset(minv, 0, sizeof(minv));
	memset(maxv, 0, sizeof(maxv));
	memset(sumv, 0, sizeof(sumv));
	memset(setv, -1, sizeof(setv));
	memset(addv, 0, sizeof(addv));
}
void pushdown(int o){
	int lc=o*2, rc=o*2+1;
	if(setv[o]>=0){
		setv[lc]=setv[rc]=setv[o];
		addv[lc]=addv[rc]=0;
		setv[o]=-1;
	}
	if(addv[o]>0){
		addv[lc]+=addv[o];
		addv[rc]+=addv[o];
		addv[o]=0;
	}
}
void maintain(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	sumv[o]=minv[o]=maxv[o]=0;
	if(R>L){
		sumv[o]=sumv[lc]+sumv[rc];
		minv[o]=min(minv[lc], minv[rc]);
		maxv[o]=max(maxv[lc], maxv[rc]);
	}
	if(setv[o]>=0){
		sumv[o]=(R-L+1)*setv[o];
		minv[o]=maxv[o]=setv[o];
	}
	minv[o]+=addv[o];
	maxv[o]+=addv[o];
	sumv[o]+=(R-L+1)*addv[o];
}
void add(int o, int L, int R, int v){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b) addv[o]+=v;
	else{
		int M=L+R>>1;
		bool flag=false;
		if(setv[o]>=0){
			pushdown(o);
			flag=true;
		}
		if(a<=M) add(lc, L, M, v);
		else if(flag) maintain(lc, L, M);
		if(b>M) add(rc, M+1, R, v);
		else if(flag) maintain(rc, M+1, R);
	}
	maintain(o, L, R);
}
void update(int o, int L, int R, int v){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b){
		addv[o]=0;
		setv[o]=v;
	}
	else{
		pushdown(o);
		int M=L+R>>1;
		if(a<=M) update(lc, L, M, v);
		else maintain(lc, L, M);
		if(b>M) update(rc, M+1, R, v);
		else maintain(rc, M+1, R);
	}
	maintain(o, L, R);
}
void query(int o, int L, int R, int psum){
	if(setv[o]>=0){
		_sum+=(setv[o]+addv[o]+psum)*(min(R, b)-max(L, a)+1);
		_min=min(_min, setv[o]+addv[o]+psum);
		_max=max(_max, setv[o]+addv[o]+psum);
	}else if(a<=L&&R<=b){
		_sum+=sumv[o]+psum*(R-L+1);
		_min=min(minv[o]+psum, _min);
		_max=max(maxv[o]+psum, _max);
	}else{
		int M=L+R>>1;
		if(a<=M) query(o*2, L, M, psum+addv[o]);
		if(b>M) query(o*2+1, M+1, R, psum+addv[o]);
	}
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while(cin>>r>>c>>m){
		init();
		while(m--){
			cin>>op;
			switch(op){
				case 1:
					int X1, Y1, X2, Y2, v;
					cin>>X1>>Y1>>X2>>Y2>>v;
					for(int x=X1-1; x<X2; x++){
						a=x*c+Y1, b=x*c+Y2;
						add(1, 1, maxlen, v);
					}
					break;
				case 2:
					cin>>X1>>Y1>>X2>>Y2>>v;
					for(int x=X1-1; x<X2; x++){
						a=x*c+Y1, b=x*c+Y2;
						update(1, 1, maxlen, v);
					}
					break;
				default:
					cin>>X1>>Y1>>X2>>Y2;
					_sum=_max=0;
					_min=0x3f3f3f3f;
					for(int x=X1-1; x<X2; x++){
						a=x*c+Y1, b=x*c+Y2;
						query(1, 1, maxlen, 0);
					}
					cout<<_sum<<' '<<_min<<' '<<_max<<endl;
					break;
			}
		}
	}
	return 0;
}
