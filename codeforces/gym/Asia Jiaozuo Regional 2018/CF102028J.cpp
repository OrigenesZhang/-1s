#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
 
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> xl(n), yl(n), xr(n), yr(n);
    vector<vector<int>> cnt(m + 1, vector<int>(m + 1));
    vector<vector<ll>> one(m + 1, vector<ll>(m + 1)), two(m + 1, vector<ll>(m + 1));
    REP(i, n) {
        scanf("%d%d%d%d", &xl[i], &xr[i], &yl[i], &yr[i]);
        xl[i]--, yl[i]--;
        cnt[xl[i]][yl[i]]++, cnt[xr[i]][yr[i]]++, cnt[xl[i]][yr[i]]--, cnt[xr[i]][yl[i]]--;
        one[xl[i]][yl[i]] += i, one[xr[i]][yr[i]] += i, one[xl[i]][yr[i]] -= i, one[xr[i]][yl[i]] -= i;
        two[xl[i]][yl[i]] += sqr(ll(i)), two[xr[i]][yr[i]] += sqr(ll(i)), two[xr[i]][yl[i]] -= sqr(ll(i)), two[xl[i]][yr[i]] -= sqr(ll(i));
    }
    int kein = 0;
    vector<int> eins(n);
    vector<pii> zwei;
    REP(i, m) REP(j, m) {
        if (i) {
            cnt[i][j] += cnt[i - 1][j];
            one[i][j] += one[i - 1][j];
            two[i][j] += two[i - 1][j];
        }
        if (j) {
            cnt[i][j] += cnt[i][j - 1];
            one[i][j] += one[i][j - 1];
            two[i][j] += two[i][j - 1];
        }
        if (i && j) {
            cnt[i][j] -= cnt[i - 1][j - 1];
            one[i][j] -= one[i - 1][j - 1];
            two[i][j] -= two[i - 1][j - 1];
        }
        if (!cnt[i][j]) {
            kein++;
        } else if (cnt[i][j] == 1) {
            eins[one[i][j]]++;
        } else if (cnt[i][j] == 2) {
            ll dif = sqr(one[i][j]) - two[i][j];
            ll plus = sqr(one[i][j]), minus = plus - 2 * dif;
            ll x = (sqrt(plus) - sqrt(minus)) / 2, y = (sqrt(plus) + sqrt(minus)) / 2;
            if (x > y) swap(x, y);
            zwei.emplace_back(x, y);
        }
    }
    sort(all(zwei));
    int fi = 0, se = 0, ans = 0;
    REP(i, n) if (eins[i] > se) {
        se = eins[i];
        if (se > fi) swap(fi, se);
    }
    ans = fi + se;
    for (int i = 0, j = 0; i < zwei.size(); i = j) {
        while (j < zwei.size() && zwei[i] == zwei[j]) j++;
        ans = max(ans, eins[zwei[i].first] + eins[zwei[i].second] + j - i);
    }
    printf("%d\n", sqr(m) - kein - ans);
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}