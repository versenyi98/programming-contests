#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[1024][101];
int indexes[1024][101][10];
int t[10][101];

void dynamic(int selection) {
    
    for (int day = 1; day <= N; day++) {
        if (dp[selection][day - 1] < dp[selection][day]) {
            for (int ii = 0; ii < K; ii++) {
                indexes[selection][day][ii] = indexes[selection][day - 1][ii];
            }
            dp[selection][day] = dp[selection][day - 1];
        }
        for (int i = 0; i < 10; i++) {
            int mask = 1 << i;
            if (selection & mask) {
                if (dp[selection][day] > dp[selection & ~(mask)][day - 1] + t[i][day - 1]) {
                    dp[selection][day] = dp[selection & ~(mask)][day - 1] + t[i][day - 1];
                    for (int ii = 0; ii < K; ii++) {
                        indexes[selection][day][ii] = indexes[selection & ~(mask)][day - 1][ii];
                    }
                    indexes[selection][day][i] = day;

                }
            }
        }        
    }
}

int main() {

    scanf("%d %d", &K, &N);

    for (int k = 0; k < pow(2, K); k++) {
        for (int n = 0; n <= N; n++) {
            dp[k][n] = 1000000000;
        }
    }

    int val;
    for (int k = 0; k < K; k++) {
        for (int n = 1; n <= N; n++) {
            scanf("%d", &val);
            t[k][n - 1] = val;
            if (val < dp[1 << k][n - 1]) {
                dp[1 << k][n] = val;
                indexes[1 << k][n][k] = n; 
            } else {
                indexes[1 << k][n][k] = indexes[1 << k][n - 1][k];
            }
            dp[1 << k][n] = min(val, dp[1 << k][n - 1]);
        }
    }

    vector<int> numbers_by_bits[10];

    for (int i = 1; i < pow(2, K); i++) {
        int mask = 1;
        int cc = 0;
        for (int j = 0; j < 10; j++) {
            if (i & mask) cc++;
            mask <<= 1;
        }
        numbers_by_bits[cc - 1].push_back(i);
    }

    for (auto i : numbers_by_bits) {
        for (auto j : i) {
            dynamic(j);
        }
    }

    cout << dp[(int)pow(2, K) - 1][N] << endl;
    for (int i = 0; i < K; i++) {
        if (i) putchar(' ');
        cout << indexes[(int)pow(2, K) - 1][N][i];
    }
    cout << endl;
}