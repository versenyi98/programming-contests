#include <bits/stdc++.h>

using namespace std;

int main() {

    unsigned long long N;
    cin >> N;

    map<pair<int, int>, bool> dislike;

    for (int i = 0; i < 10; i++) {
        int f1;
        cin >> f1;
        
        for (int j = 0; j < 9; j++) {
            int f2;
            cin >> f2;

            dislike[{f1, f2}] = true;
            dislike[{f2, f1}] = true;
        }
    }

    int counter = 0;

    for (auto i : dislike) counter++;
    cout << ((N * (N - 1)) / 2) - (counter / 2) << endl;

}