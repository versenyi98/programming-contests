#include <bits/stdc++.h>

using namespace std;

uint64_t dp[201][201];
bool taken[201][201];

int n;

uint64_t dy(int rem, int index) {

    if (rem < 0) return 0;
    if (rem == 0) return 1;
    if (index > n) return 0;

    if (taken[index][rem]) return dp[index][rem];

    taken[index][rem] = true;
    dp[index][rem] = dy(rem - index, index + 1) + dy(rem, index + 1);

    return dp[index][rem];
}

int main() {
    cin >> n;
    cout << dy(n, 1) << endl;
}