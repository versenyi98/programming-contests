#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (cin >> n) {
        map<int, vector<int>> sees;

        for (int i = 0; i < n; i++) {
            int router;
            char trash;

            cin >> router;
            cin >> trash;

            string line;
            getline(cin, line);
            if (line.length() == 0) continue;
            
            int akt = 0;
            for (int j = 0; j < line.length(); j++) {
                if (line[j] == ',') {
                    sees[router].push_back(akt);
                    akt = 0;
                } else {
                    akt = akt * 10 + line[j] - '0';
                }
            }         
            if (akt != 0) sees[router].push_back(akt);
        }

        int qv;
        cin >> qv;
        cout << "-----\n";
        for (int i = 0; i < qv; i++) {
            map<int, bool> taken;
            queue<pair<int, vector<int>>> q;

            int from, to;

            cin >> from >> to;

            q.push({from, {from}});

            while (!q.empty() && q.front().first != to) {

                pair<int, vector<int>> t = q.front();
                q.pop();

                if (taken[t.first]) continue;
                taken[t.first] = true;

                for (int j : sees[t.first]) {
                    if (!taken[j]) {
                        vector<int> v = t.second;
                        v.push_back(j);
                        q.push({j, v});
                    }
                }
            }

            if (q.empty()) {
                cout << "connection impossible" << endl;
            } else {
                for (int j = 0; j < q.front().second.size(); j++) {
                    if (j) cout << " ";
                    cout << q.front().second[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}