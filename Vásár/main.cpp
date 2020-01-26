#include <bits/stdc++.h>

using namespace std;

int termekek;
int teherbiras;
int tomeg[100], egysegar[100], mennyiseg[100], minimalis[100];

int main() {
    cin >> termekek;
    cin >> teherbiras;
    
    int profit = 0;
    bool impossible = false;

    for (int i = 0; i < termekek; i++) {
        cin >> tomeg[i] >> egysegar[i] >> mennyiseg[i] >> minimalis[i];
        profit += minimalis[i] * egysegar[i];
        mennyiseg[i] -= minimalis[i];
        teherbiras -= minimalis[i] * tomeg[i];

        if (mennyiseg[i] < 0 || teherbiras < 0) impossible = true;
    }
    if (impossible) {
        cout << -1 << endl;
    } else {
        int dp[termekek + 1][teherbiras + 1];
        for (int i = 0; i < termekek + 1; i++) dp[i][0] = 0;
        for (int i = 0; i < teherbiras + 1; i++) dp[0][i] = 0;

        for (int i = 1; i <= termekek; i++) {
            for (int j = 1; j <= teherbiras; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= mennyiseg[i - 1]; k++) {
                    if (k * tomeg[i - 1] <= j && dp[i - 1][j - k * tomeg[i - 1]] + k * egysegar[i - 1] > dp[i][j]) {
                        dp[i][j] = dp[i - 1][j - k * tomeg[i - 1]] + k * egysegar[i - 1];
                    }
                }
            }
        }
        cout << profit + dp[termekek][teherbiras] << endl;
    }
}