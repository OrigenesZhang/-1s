//大模拟
#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef deque<int> deq;
vector<deq> state;
set<vector<deq>> s;
bool vis[10];
int pos, step;
inline void init(){
	memset(vis, false, sizeof(vis));
	step=pos=0;
	s.clear();
	state.clear();
}
bool read(){
	int tmp;
	deq deck;
	for(int i=0; i<52; i++){
		cin>>tmp;
		if(!tmp) return false;
		deck.push_back(tmp);
	}
	state.push_back(deck);
	deck.clear();
	for(int i=0; i<7; i++)
		state.push_back(deck);
	return true;
}
inline bool judge(){
	for(int i=1; i<=7; i++)
		if(!state[i].empty()) return false;
	return true;
}
bool deal(deq& cur, int n, int* num){
	for(int i=0; i<n; i++){
		if(cur.empty()) return false;
		num[2-i]=cur.back();
		cur.pop_back();
	}
	for(int i=0; i<3-n; i++){
		if(cur.empty()) return false;
		num[i]=cur.front();
		cur.pop_front();
	}
	return true;
}
int main(){
	while(read()){
		s.insert(state);
		while(true){
			if(state[0].empty()){
				cout<<"Loss: "<<step<<endl;
				break;
			}
			do{
				pos=(pos+1)%7+1;
			}while(vis[pos]);
			step++;
			int play=state[0].front();
			state[0].pop_front();
			state[pos].push_back(play);
			bool flag=true;
			while(flag){
				flag=false;
				for(int i=1; i<=3; i++){
					int num[3], tot=0;
					deq cur=state[pos];
					if(!deal(cur, i, num)) break;
					for(int j=0; j<3; j++)
						tot+=num[j];
					if(tot==10||tot==20||tot==30){
						flag=true;
						for(int j=0; j<3; j++)
							state[0].push_back(num[j]);
						state[pos]=cur;
						break;
					}
				}
			}
			if(state[pos].empty()) vis[pos]=true;
			if(judge()){
				cout<<"Win : "<<step<<endl;
				break;
			}
			if(s.find(state)!=s.end()){
				cout<<"Draw: "<<step<<endl;
				break;
			}
			s.insert(state);
		}
		init();
	}
	return 0;
}
