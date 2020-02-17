#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int N, K;
void shuffle_() {

    int arr2[100000];
    
    for (int i = 0; i < (N + 1) / 2; i++) { 
        arr2[i] = arr[i * 2];
    }

    for (int i = 0; i < N / 2; i++) {
        arr2[i + (N + 1) / 2] = arr[i * 2 + 1];
    }

    for (int i = 0; i < (N + 1) / 2; i++) {
        arr[N - 1 - i * 2] = arr2[i];
    }

    for (int i = 0; i < N / 2; i++) {
        arr[N - 1 - i * 2 - 1] = arr2[N - 1 - i];
    }

}

int main() {

    cin >> N >> K;

    K = K % 4;

    for (int i = 0; i < N; i++) arr[i] = i + 1;

    for (int i = 0;  i < K; i++) shuffle_();

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}