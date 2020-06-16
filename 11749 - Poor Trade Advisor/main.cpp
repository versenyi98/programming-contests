#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    while (cin >> n >> m, n || m) {

        vector<pair<int, long>> road[n];
        bool visited[n];
        long maximumPPA = LONG_MIN;

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int f, t;
            long ppa;
            cin >> f >> t >> ppa;
            road[f - 1].push_back({t - 1, ppa});
            road[t - 1].push_back({f - 1, ppa});

            maximumPPA = max(maximumPPA, ppa);
        }

        int max_cities = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                bool f = false;

                for (auto j : road[i]) 
                    if (j.second == maximumPPA) {
                        f = true;
                        break;
                    }

                if (!f) continue;

                queue<int> q;
                q.push(i);

                int counter = 0;

                while (q.size()) {
                    auto front = q.front();
                    q.pop();

                    if (visited[front]) continue;
                    visited[front] = true;

                    counter++;

                    for (auto j : road[front]) {
                        if (j.second == maximumPPA && !visited[j.first]) {
                            q.push(j.first);
                        }
                    }
                }
                max_cities = max(max_cities, counter);
            }
        }
        cout << max_cities << endl;
    }
}