#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> v;

int result[1000001];
int parent[1000001];
int len[1000001];
int val[1000001];

void printParent(int pos, int rem) {
    if (rem == 0) return;
    printParent(v[parent[pos]].first, rem - 1);
    cout << (val[pos] + 1) << (rem == 1 ? " " : "");

}

int main() {

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    for (int i = 0; i <= 1000001; i++) {
        result[i] = 0;
    }

    vector<int> taken_positions;

    int max_val = 0;
    int max_pos = 0;

    for (int i = 0; i < N; i++) {

        if (result[v[i].first] < v[i].second) {
            parent[v[i].first] = i;
            result[v[i].first] = v[i].second;
            len[v[i].first] = 1;
            val[v[i].first] = i;
        }

        for (int j = 0; j < taken_positions.size(); j++) {
            if (v[i].first - 20 >= taken_positions[j]) {
                if (result[v[i].first] >= result[taken_positions[j]] + v[i].second) {

                } else {
                    result[v[i].first] = v[i].second + result[taken_positions[j]];
                    parent[v[i].first] = j;
                    len[v[i].first] = len[taken_positions[j]] + 1;
                    val[v[i].first] = i;
                }
            }
        }

        if (result[v[i].first] > max_val) {
            max_val = result[v[i].first];
            max_pos = v[i].first;
        }

        taken_positions.push_back(v[i].first);
    }

    cout << max_val << endl << len[max_pos] << " ";
    printParent(max_pos, len[max_pos]);
    cout << endl;
}