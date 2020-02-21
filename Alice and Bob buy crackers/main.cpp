#include <bits/stdc++.h>

using namespace std;

int n;
bool taken[21][20001];
map<int, bool> already_taken;
int cost[1000];
int res = 0;

void knapsack(int index, int current) {
    if (index == 0) {
        if (already_taken[current]) return;
        already_taken[current] = true;
        if (current != 0 && current % 2 == 0) res++;
        return;
    }
    if (taken[index][current]) return;

    knapsack(index - 1, current);
    knapsack(index - 1, current + cost[index - 1]);
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 20001; j++) {
            taken[i][j] = false;
        }
    }

    knapsack(n, 0);
    cout << res << endl;
    return 0;
}