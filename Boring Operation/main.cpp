#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;

    unsigned long long int minimum = LONG_LONG_MAX;
    unsigned long long int maximum = 0;

    unsigned long long int temp;

    cin >> N;

    while (N--) {

        cin >> temp;

        if (temp > 500000000) {
            temp = 1000000000 - temp;
        }

        minimum = min(temp, minimum);
        maximum = max(temp, maximum);
    }

    cout << maximum - minimum << endl;
}