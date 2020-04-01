#include <bits/stdc++.h>

using namespace std;

int n, k;
string str;
int cc[200000][26];

int differ(int u, int v) {

    int mx = 0;

    for (int i = 0; i < 26; i++) {
        mx = max(mx, cc[u][i] + cc[v][i]);
    }
    return n/k * 2 - mx;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        cin >> str;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 26; j++) {
                cc[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            cc[i % k][str[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += differ(i, k - 1 - i);
        }

        cout << ans / 2 << endl;
    }
}
