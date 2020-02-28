#include <bits/stdc++.h>

using namespace std;

uint64_t dp[501][501];
bool taken[501][501];

int N, M;

uint64_t dy(int rem, int index) {

    if (rem == 0) return 1;
    if (rem < 0) return 0;
    if (index > M) return 0;

    if (taken[rem][index]) return dp[rem][index];
    dp[rem][index] = dy(rem - index, index + 1) + dy(rem, index + 1);

    return dp[rem][index];
}

int main() {
    cin >> N >> M;
    cout << dy(N, 1) << endl;
}