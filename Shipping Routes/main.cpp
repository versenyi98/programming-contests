#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    cout << "SHIPPING ROUTES OUTPUT\n";

    for (int i = 0; i < test_cases; i++) {
        cout << endl << "DATA SET  " << i + 1 << endl << endl;

        map<string, vector<string>> connections;

        int N, M, P;

        cin >> N >> M >> P;

        string str;
        for (int j = 0; j < N; j++) {
            cin >> str;
        }

        string from, to;
        for (int j = 0; j < M; j++) {
            cin >> from >> to;
            connections[from].push_back(to);
            connections[to].push_back(from);
        }

        int limit;
        for (int j = 0; j < P; j++) {
            queue<pair<string, int>> q;
            map<string, bool> touched;

            cin >> limit >> from >> to;
            q.push({from, 0});

            pair<string, int> current;
            while (!q.empty() && q.front().first != to) {
                current = q.front();
                q.pop();

                touched[current.first] = true;
                for (auto j : connections[current.first]) {
                    if (!touched[j]) {
                        q.push({j, current.second + 1});
                    }
                }
            }
            
            if (!q.empty()) {
                cout << "$" << q.front().second * 100 * limit << endl;
            } else {
                cout << "NO SHIPMENT POSSIBLE" << endl;
            }
        }
    }
    cout << endl << "END OF OUTPUT\n";
}