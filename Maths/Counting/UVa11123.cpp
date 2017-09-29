//真暴力
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
const double pi=4.0*atan(1.0);
int cs=1, n;
typedef pair<double, double> Point;
struct Line{
	double k, c, l;
	Line(Point a=make_pair(0, 0), Point b=make_pair(0, 0)){
		this->k=atan2(a.second-b.second, a.first-b.first);
		this->c=(fabs(a.first-b.first)<eps?a.first:a.second-a.first*(a.second-b.second)/(a.first-b.first));
		this->l=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
	}
	bool operator < (const Line& rhs) const{
		return k<rhs.k;
	}
};
struct State{
	double c, l;
	State(double c, double l){
		this->c=c;
		this->l=l;
	}
	bool operator < (const State& rhs) const{
		return fabs(c-rhs.c)>eps?c<rhs.c:l<rhs.l;
	}
};
Point p[210];
vector<Line> line;
vector<State> state;
inline bool cmp(State a, State b){
	return a.l<b.l;
}
int olap(){
	sort(state.begin(), state.end());
	int res=0, cnt=1, cur=1;
	for(int i=1; i<state.size(); i++){
		if(fabs(state[i].c-state[i-1].c)>eps){
			res+=cnt*(cnt-1)>>1;
			res-=cur*(cur-1)>>1;
			cnt=cur=0;
		}
		if(fabs(state[i].l-state[i-1].l)>eps){
			res-=cur*(cur-1)>>1;
			cur=0;
		}
		cur++;
		cnt++;
	}
	res+=cnt*(cnt-1)>>1;
	res-=cur*(cur-1)>>1;
	sort(state.begin(), state.end(), cmp);
	cnt=1;
	for(int i=1; i<state.size(); i++){
		if(fabs(state[i].l-state[i-1].l)>eps){
			res+=cnt*(cnt-1)>>1;
			cnt=0;
		}
		cnt++;
	}
	res+=cnt*(cnt-1)>>1;
	return res;
}
int main(){
	while(cin>>n){
		if(!n) break;
		line.clear();
		for(int i=0; i<n; i++){
			double x, y;
			cin>>x>>y;
			p[i]=make_pair(x, y);
			for(int j=0; j<i; j++)
				line.push_back(Line(p[j], p[i]));
		}
		for(int i=0; i<line.size(); i++)
			if(line[i].k<eps) line[i].k+=pi;
		sort(line.begin(), line.end());
		int res=0;
		if(line.empty()){
			cout<<"Case "<<cs++<<": "<<0<<endl;
			continue;
		}
		state.clear();
		state.push_back(State(line[0].c, line[0].l));
		for(int i=1; i<line.size(); i++){
			if(fabs(line[i].k-line[i-1].k)>eps){
				res+=state.size()*(state.size()-1)/2-olap();
				state.clear();
			}
			state.push_back(State(line[i].c, line[i].l));
		}
		res+=state.size()*(state.size()-1)/2-olap();
		cout<<"Case "<<cs++<<": "<<res<<endl;
	}
	return 0;
}
