#include <bits/stdc++.h>

using namespace std;

uint64_t dp[51][51];
bool taken[51][51];

uint64_t dy(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (i == 0 && j == 0) return 1;

    if (taken[i][j]) return dp[i][j];
    taken[i][j] = true;
    
    if (i == j) {
        dp[i][j] = dy(i - 1, j - 1) + dy(i - 2, j - 2) + dy(i - 3, j - 3) + dy(i - 2, j - 3) + dy(i - 3, j - 2);
    } else if (abs(i - j) >= 2) {
        if (i < j) {
            dp[i][j] = dy(i, j - 2) + dy(i, j - 3);
        } else {
            dp[i][j] = dy(i - 2, j) + dy(i - 3, j);
        }
    }else {
        dp[i][j] = dy(i - 2, j - 2) + dy(i - 3, j - 3) + dy(i - 2, j - 3) + dy(i - 3, j - 2);
    }
    
    return dp[i][j];
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            taken[i][j]  = false;
            dp[i][j] = 0;
        }
    }
    
    cout << dy(n, n) << endl;
}