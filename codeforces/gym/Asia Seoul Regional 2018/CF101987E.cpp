#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<pair<int, int >> vl;
const double EPS = 1e-9;
 
bool is_valid(double mid) {
  int stage = 0;
  int stage1min = 0;
  int stage1max = 0;
  int stage2min = 0;
  int stage2max = 0;
 
  for (int i = 0; i < n; ++i) {
    if (stage == 0) {
      if (vl[i].second > mid + EPS) {
//        cout << "vl[i].second << mid" << endl;
//        cout << vl[i].second << " " << mid << endl;
        stage++;
        stage1min = vl[i].second;
        stage1max = vl[i].second;
      }
    } else if (stage == 1) {
      if (abs(vl[i].second - stage1min) > 2 * mid + EPS || abs(vl[i].second - stage1max) > 2 * mid + EPS) {
        stage++;
        stage2min = vl[i].second;
        stage2max = vl[i].second;
      } else {
        stage1min = min(vl[i].second, stage1min);
        stage1max = max(vl[i].second, stage1max);
//        cout << mid << endl;
//        cout << stage1min << " " << stage1max << endl;
      }
    } else if (stage == 2) {
      if (abs(vl[i].second - stage2min) > 2 * mid + EPS || abs(vl[i].second - stage2max) > 2 * mid + EPS) {
        return false;
      } else {
        stage2min = min(vl[i].second, stage2min);
        stage2max = max(vl[i].second, stage2max);
      }
    } else {
      return false;
    }
  }
 
  if (stage < 2) {
    return true;
  } else if (stage == 2 && stage1max - mid < stage2min + mid + EPS) {
    return true;
  }
  return false;
}
 
int main() {
  cin >> n;
 
  double left = 0;
  double right = 0;
  for (int i = 1; i <= n; ++i) {
    int v, l;
    scanf("%d%d", &v, &l);
    vl.emplace_back(v, l);
    right = max(right, (double) l);
  }
 
  sort(vl.begin(), vl.end());
  if (vl[0].first == 0) left = vl[0].second;
  int times = 0;
  while (true) {
    double mid = left + (right - left) / 2;
    if (is_valid(mid)) {
      right = mid;
    } else {
      left = mid;
    }
    times++;
    if (times > 100) {
      break;
    }
  }
 
  cout << fixed << setprecision(1) << left;
 
  return 0;
}