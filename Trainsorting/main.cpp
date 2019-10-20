#include <iostream>
#include <cmath>

using namespace std;

int ascending[2][2000], decreasing[2][2000];
int n;

void magic_function() {

    ascending[1][n - 1] = 1;
    decreasing[1][n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        int max_asc = 0;
        int max_decr = 0;

        for (int j = i + 1; j < n; j++) {
            if (ascending[0][i] > ascending[0][j]) {
                max_asc = max(max_asc, ascending[1][j]);
            }
            if (decreasing[0][i] < decreasing[0][j]) {
                max_decr = max(max_decr, decreasing[1][j]);
            }
        }
        ascending[1][i] = max_asc + 1;
        decreasing[1][i] = max_decr + 1;

    }
}


int main() {

    cin >> n;


    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        ascending[0][i] = temp;
        decreasing[0][i] = temp;
    }
    magic_function();

    int max_length = 0;
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, ascending[1][i] + decreasing[1][i] - 1);
    }
    cout << max_length << endl;

    return 0;
}
