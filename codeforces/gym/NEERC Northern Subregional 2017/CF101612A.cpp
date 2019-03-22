#include <iostream>
#include <cstring>
using namespace std;

const int N = 1234567;
const int INF = int(1e8);

int n;
int main() {
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    cin >> n;
    if (n % 3 == 0) cout << n / 3 * 7 << '\n';
    else if (n % 3 == 1) cout << n / 3 * 7 - 3 << '\n';
    else cout << n / 3 * 7 + 1 << '\n';
    fclose(stdout);
    return 0;
}