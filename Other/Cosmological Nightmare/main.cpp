#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, M;
    int x, y;
    
    vector<pair<int, int>> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {

        vector<bool> taken;
        for (int j = 0; j < N; j++) {
            taken.push_back(false);
        }

        bool err = false;
        cin >> x >> y;
        for (int j = 0; j < N; j++) {
            if (taken[j]) continue;
            for (int k = j + 1; k < N; k++) {
                if (taken[k]) continue;
                if ((x == 0 && v[j].first == v[k].first) || (x != 0 && (v[j].first - v[k].first) % x == 0)) {
                    if ((y == 0 && v[j].second == v[k].second) || (y != 0 && (v[j].second - v[k].second) % y == 0)) {
                        if (x == 0 || y == 0 || ((v[j].first - v[k].first) / x == (v[j].second - v[k].second) / y)) {
                            taken[j] = true;
                            taken[k] = true;
                            break;
                        }

                    }
                }
            }
            if (!taken[j]) {
                err = true;
                break;
            }
        }

        if (err) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}