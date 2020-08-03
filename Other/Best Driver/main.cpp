#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x1, x2, c1, c2;
        cin >> x1 >> x2 >> c1 >> c2;

        printf("%.8f\n", ((c2) * (x1 + x2) - (c1 * x1)) / x2);
    }
}