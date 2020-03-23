#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        int N;
        scanf("%d", &N);
        int A[N];
        int minimum = INT_MAX;

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        sort(A, A + N);
        for (int i = 0; i < N - 1; i++) {
                minimum = min(minimum, (A[i] ^ A[i + 1]));
        }
        
        cout << minimum << endl;
    }
}