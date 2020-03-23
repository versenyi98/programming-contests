#include <iostream>
#include <stdio.h>

using namespace std;

int connections[300000];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        connections[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        connections[x - 1]++;
        connections[y - 1]++;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (connections[i] == 1) result++;
    }
    cout << max(0, result - 2) << endl;
}
