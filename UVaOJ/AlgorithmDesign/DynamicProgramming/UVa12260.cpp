// 复杂度O(nlgn)
// 先按照Petra的选择顺序排序并假设Jan也使用Petra的策略按照Petra认可的价值进行挑选
// 我们猜想在这样的分组序列中, Jan可以对自己分组内的物品按照从后往前的顺序选择是否与
// Petra分组内且在该物品之后被选取的任意物品进行一次交换并且当被交换的对象价值为全部
// 可能被交换的对象中的最大值且大于该物品的价值, Jan将会进行这样一次交换并且该算法
// 保证产生最优解。
// 现在我们来证明这个猜想的正确性
// 定义每轮挑选开始于Jan
// 如果Jan在剩下一个或两个物品时进行最后一轮挑选
// 那么他或者并没有选择 或者将选择对他而非Petra最优的情况
// 假设该算法对于倒数k轮可行并且最优
// 若有(k+1)轮以上的挑选存在 则对于倒数第(k+1)轮挑选
// 可行性：
// 如果选择进行交换, 那么Petra必然会愿意且会于同一轮将释放的物品拿走因为她将得到一个
// 当前可能得到的价值最高的物品
// 最优性：
// 如果选择进行交换, 那么Jan将会得到一个价值比当前释放物品更高的物品（交换条件）, 从而
// 使得当轮获得的价值提升, 由于我们先前的假设, 在该轮结束后该算法将产生对最后k轮的全局
// 最优解, 从而对于倒数(k+1)轮交换最优
// 由数学归纳法得猜想成立

// 该问题同样可以以动态规划的思想来解决
// 在同样的排序后令dp[i][j]为前i个物品被Jan拿走j个时对于Jan的最大效用, 即让二元数对
// <对Jan的最大value, 对Petra的最小value>最优
// 转移方程：
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + value[i])
// 假设加法和大于小于号均有定义
// 复杂度 O(n^2)

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=1234;
struct Goodie{
	int p, j;
	bool isp;
	bool operator < (const Goodie& rhs) const{
		if(j!=rhs.j) return j<rhs.j;
		return p>rhs.p;
	}
	bool operator > (const Goodie& rhs) const{
		return rhs<*this;
	}
}g[maxn];
int T, n;
char s[10];
priority_queue<pair<Goodie, int>> q;
inline bool cmp(const Goodie& a, const Goodie& b){
	if(a.p!=b.p) return a.p>b.p;
	return a.j<b.j;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", s);
		bool flag=(s[0]=='P');
		for(int i=0; i<n; i++)
			scanf("%d%d", &g[i].p, &g[i].j);
		sort(g, g+n, cmp);
		for(int i=0; i<n; i++){
			g[i].isp=flag;
			flag^=1;
		}
		if(!q.empty()){
			priority_queue<pair<Goodie, int>> tmp;
			swap(q, tmp);
		}
		int cur=n-1;
		if(g[cur].isp){
			q.push(make_pair(g[cur], cur));
			cur--;
		}
		while(cur>=0){
			pair<Goodie, int> u;
			if(q.empty()) goto label;
			u=q.top();
			if(g[cur]<u.first){
				q.pop();
				g[cur].isp=true;
				g[u.second].isp=false;
				q.push(make_pair(g[cur], cur));
			}
			label:
			cur--;
			if(cur>=0) q.push(make_pair(g[cur], cur));
			cur--;
		}
		int ansp=0, ansj=0;
		for(int i=0; i<n; i++){
			if(g[i].isp) ansp+=g[i].p;
			else ansj+=g[i].j;
		}
		printf("%d %d\n", ansp, ansj);
	}
	return 0;
}
