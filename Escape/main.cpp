#include <iostream>
#include <map>

#define pii pair<int, int>

using namespace std;

map<pii, bool> can_pass;

int n, m;
int faust;

bool visited[10001];
string result = "";

int index_to_cell_or_inter(int index) {
    if (index < n) return index + 1;
    return 5001 + index - n;
}

int inter_or_cell_to_index(int ic) {
    if (ic >= n) return ic - 5000 + n;
    return ic - 1;
}

bool recursion(int i) {

    if (visited[i]) return false;
    visited[i] = true;

    if (can_pass[{0, i}]) {
        result = "0\n";
        result = to_string(i) + "\n" + result;
        return true;
    }

    for (int j = 0; j <= n + m; j++) {
        if (can_pass[{index_to_cell_or_inter(j), i}]) {
            bool value = recursion(index_to_cell_or_inter(j));
            if (value) {
                result = to_string(i) + "\n" + result;
                return true;
            }
        }
    }

    return false;
}

int main() {

    cin >> n >> m >> faust;

    int a, b;
    while (scanf("%d%d", &a, &b) == 2 && (a != 0 || b != 0)) {
        can_pass[{a, b}] = true;
        can_pass[{b, a}] = true;
    }

/*
    for (int i = -1; i < n + m; i++) {
        int ii = index_to_cell_or_inter(i);
        for (int j = -1; j < n + m; j++) {
            int jj = index_to_cell_or_inter(j);
            cout << can_pass[{ii, jj}] << " ";
        }
        cout << endl;
    }
*/ 
    recursion(faust);
    cout << result;
}