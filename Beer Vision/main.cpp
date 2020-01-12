#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<pair<int, int>> v;
    vector<bool> good;
    map<pair<int, int>, bool> point;

    int n;
    int x, y;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
        point[{x, y}] = true;
    }

    set<pair<int, int>> result;

    for (int i = 1; i < n; i++) {
        pair<int, int> vec = {v[0].first - v[i].first, v[0].second - v[i].second};

        if (vec.first < 0) {
            vec.first *= -1;
            vec.second *= -1;
        } else if (vec.first == 0) {
            vec.second = abs(vec.second);
        }

        bool ins = true;
        for (int j = 0; j < n; j++) {
            if (!point[{v[j].first + vec.first, v[j].second + vec.second}] && !point[{v[j].first - vec.first, v[j].second - vec.second}]) {
                ins = false;
                break;
            }
        }
        if (ins) result.insert(vec);
    }

    cout << result.size() * 2 << endl;

    return 0;
}