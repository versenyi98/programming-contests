#include <bits/stdc++.h>

using namespace std;

int N, K;

vector<int> v;

int main() {

    cin >> N >> K;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int median = v[N/2];

    for (int i = 0; i < N; i++) {
        if (K && v[i] == median) {
            v[i]++;
            K--;
        }
    }
    
    sort(v.begin(), v.end());
    cout << v[N/2] << endl;
}