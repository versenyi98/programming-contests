#include <iostream>
#include <cmath>

int n, m;
using namespace std;

int szamol() {

    int count = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                if (pow(i, 2) + pow(j, 2) == pow(k, 2)) count++;
            }
        }
    }

    return count;
}

int main() {
    cin >> m >> n;

    int result = (m + 1) * (n - 2) + szamol();
    cout << result << endl;

}