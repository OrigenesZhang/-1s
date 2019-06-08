#include <bits/stdc++.h>

using namespace std;

int M;
int N;
char matrix[112][112];
int S, X, Y;

void place_char(int x, int y, char ch) {
  if (x >= 0 && x < M && y >= 0 && y < M) {
    matrix[x][y] = ch;
  }
}

int main() {
  while (cin >> M >> N) {
    memset(matrix, char(46), sizeof(matrix));
    for (int num = 0; num < N; ++num) {
      cin >> S >> X >> Y;
      if (S == 0) {
        place_char(X - 1, Y, char(95));
        place_char(X, Y, char(111));
        place_char(X + 1, Y, char(95));
      } else {
        // root
        place_char(X - 1, Y, char(95));
        place_char(X, Y, char(124));
        place_char(X + 1, Y, char(95));

        // left branches, trunk, right branches
        for (int y = Y + 1; y <= Y + S; ++y) {
          place_char(X - 1, y, char(47));
          place_char(X, y, char(124));
          place_char(X + 1, y, char(92));
        }

        // top
        place_char(X, Y + S + 1, char(94));
      }
    }

    for (int i = 0; i <= M + 1; ++i) {
      cout << char(42);
    }
    cout << endl;

    for (int j = M - 1; j >= 0; --j) {
      cout << char(42);
      for (int i = 0; i < M; ++i) {
        cout << matrix[i][j];
      }
      cout << char(42);
      cout << endl;
    }

    for (int i = 0; i <= M + 1; ++i) {
      cout << char(42);
    }
    cout << endl;
    cout << endl;
  }

  return 0;
}