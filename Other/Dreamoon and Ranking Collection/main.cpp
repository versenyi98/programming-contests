#include <bits/stdc++.h>

using namespace std;

int main() {

    int tt;
    cin >> tt;

    for (int i = 0; i < tt; i++) {

        int n, x;
        cin >> n >> x;

        int round[100];
        for (int k = 0; k < 100; k++) {
            round[k] = 0;
        }

        for (int k = 0; k < n; k++) {
            int tp;
            cin >> tp;
            round[tp - 1]++;
        }

        int ind = 0;
        while (((ind < 100 && round[ind] > 0) || x > 0)) {
            if (ind >= 100 || round[ind] == 0) {
                x--;
            }
            ind++;
        }
        cout << ind << endl;
    }
}