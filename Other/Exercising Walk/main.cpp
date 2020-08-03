#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        int a, b, c, d, x, x1, x2, y, y1, y2;

        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);

        int x_diff = b - a;
        int y_diff = d - c;

        if ((x1 == x2 && (a > 0 || b > 0)) || (y1 == y2 && (c > 0 || d > 0)) || (x + x_diff > x2 || x + x_diff < x1) || (y + y_diff > y2 || y + y_diff < y1)) {
            cout << "No\n";
        } else {
            cout << "Yes" << endl;
        }
    }
}