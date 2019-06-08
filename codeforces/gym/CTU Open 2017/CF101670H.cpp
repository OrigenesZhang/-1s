#include <bits/stdc++.h>

using namespace std;

int N;
int arr[212345];
int counter = 0;

int main() {
  while (cin >> N) {
    counter = 0;
    for (int num = 1; num <= N; ++num) {
      cin >> arr[num];
    }

    for (int idx = 1; idx <= N; ++idx) {
      while (arr[idx] != idx) {
        swap(arr[idx], arr[arr[idx]]);
        counter++;
      }
    }

    cout << counter << endl;
  }

  return 0;
}