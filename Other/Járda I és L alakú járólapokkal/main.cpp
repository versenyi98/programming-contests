#include <bits/stdc++.h>

using namespace std;

int N;

bool taken[30][30];
uint64_t dp[30][30];

uint64_t count(int i, int j) {

    if (i == 0 && j == 0) return 1;

    if (i < 0 || j < 0) return 0;

    if (abs(i - j) >= 2) return 0;

    if (taken[i][j]) return dp[i][j];
    taken[i][j] = true;

    if (i == j) {
        dp[i][j] = count(i - 2, j - 2) +  count(i - 1, j - 1);
    } else {
        dp[i][j] = count(i - 2, j) + count(i, j - 2);
    }
    
    dp[i][j] = dp[i][j]  + count(i - 2, j - 1) + count(i - 1, j - 2);
    return dp[i][j];
}

int main() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            taken[i][j] = false;
        }
    }
    while (cin >> N) 
    cout << count(N, N) << endl;
}