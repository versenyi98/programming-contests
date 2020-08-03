#include <bits/stdc++.h>

using namespace std;

uint64_t dp[40][40];
bool taken[40][40];
int n;

uint64_t dynamic(int i, int j) {

    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (abs(i - j) > 2) return 0;

    if (taken[i][j]) return dp[i][j];
    taken[i][j] = true;

    dp[i][j] = 0;
    if (i == j) {
        dp[i][j] = 2 * dynamic(i - 1, j - 1) + dynamic(i - 2, j - 2) + dynamic(i - 2, j - 1) + dynamic(i - 1, j - 2);
    } else {
        if (i > j) {
            dp[i][j] = dynamic(i - 2, j) + dynamic(i - 1, j);
        } else {
            dp[i][j] = dynamic(i, j - 2) + dynamic(i, j - 1);
        }
    }

    return dp[i][j];
}

int main() {

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            taken[i][j] = false;
        }
    }
    cin >> n;
    cout << dynamic(n, n) << endl;
}