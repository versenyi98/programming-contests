#include <bits/stdc++.h>

using namespace std;

bool taken[81];
int dp[81];

int n;

int dynamic(int s) {

    if (s == 0) return 1;
    if (s < 0) return 0;
    if (taken[s]) return dp[s];

    taken[s] = true;
    dp[s] = dynamic(s - 1) + dynamic(s - 2) + dynamic(s - 3);
    return dp[s];
}

int main() {

    for (int i = 0; i < 81; i++) {
        taken[i] = false;
    }

    cin >> n;
    cout << dynamic(n) << endl;
} 