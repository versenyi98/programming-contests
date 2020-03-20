#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, x2, x3;
        int y1, y2, y3;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        int diff_1 = abs(x3 - x1) + abs(y3 - y1);
        int diff_2 = max(abs(x3 - x2), abs(y3 - y2));
        if (diff_1 < diff_2) {
            cout << "First" << endl;
        } else if (diff_2 < diff_1) {
            cout << "Second" << endl;
        } else {
            cout << "Same time" << endl;
        }
    }
}