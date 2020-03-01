#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {

    cin >> n >> k;

    int left = k;
    int current_index = 1;
    int saved_index = 0;
    int saved_val, temp_val;

    cin >> saved_val;
    n--;
    while (n--) {
        cin >> temp_val;

        current_index++;

        if (temp_val > saved_val) {
            saved_val = temp_val;
            left = k;
            saved_index = current_index;
        } else {
            left--;
        }

        if (left == 0) break;
    }

    cout << saved_index << endl;
}