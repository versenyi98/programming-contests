#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        map<char, vector<char>> connections;
        map<char, double> export_value;
        map<char, bool> taken;

        priority_queue<pair<double, char>> pq;
        queue<pair<double, int>> q;
    
        char planet;
        double export_val;
        string cons;

        for (int i = 0; i < n; i++) {
            cin >> planet >> export_val >> cons;

            for (int j = 0; j < cons.length(); j++) {
                connections[planet].push_back(cons[j]);
                connections[cons[j]].push_back(planet);
            }

            export_value[planet] = export_val;
            taken[planet] = false;
        }

        for (auto i : connections['*']) {
            q.push({0, i});
        }

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            if (taken[current.second]) continue;

            taken[current.second] = true;
            pq.push({export_value[current.second] * pow(0.95, current.first), -current.second});

            for (auto i : connections[current.second]) {
                if (!taken[i]) {
                    q.push({current.first + 1, i});
                }
            }
        }
        cout << "Import from " << static_cast<char>(-pq.top().second) << endl;        
    }
}