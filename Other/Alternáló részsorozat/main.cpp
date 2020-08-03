#include <bits/stdc++.h>

using namespace std;

int NUMBERS;
int numbers[100000];

int ALT_SIZE1;
int ALT1[100000];
int alt1[100000];
int alt1_index[100000];

int ALT_SIZE2;
int ALT2[100000];
int alt2[100000];
int alt2_index[100000];

int alt1_fun(int n) {

    int j = ALT_SIZE1;

    while (j > 0) {
        if (j % 2 == 0 && ALT1[j - 1] > n) break;
        if (j % 2 == 1 && ALT1[j - 1] < n) break;
        j--;
    }

    if (j == ALT_SIZE1) {
        ALT1[j] = n;
        ALT_SIZE1++;
    } else {

        if (j % 2 == 1 && ALT1[j] < n) {
            ALT1[j] = n;
        } else if (j % 2 == 0 && ALT1[j] > n) {
            ALT1[j] = n;
        }
    }

    return j + 1;
}

int alt2_fun(int n) {

    int j = ALT_SIZE2;

    while (j > 0) {
        if (j % 2 == 0 && ALT2[j - 1] < n) break;
        if (j % 2 == 1 && ALT2[j - 1] > n) break;
        j--;
    }

    if (j == ALT_SIZE2) {
        ALT2[j] = n;
        ALT_SIZE2++;
    } else {

        if (j % 2 == 1 && ALT2[j] > n) {
            ALT2[j] = n;
        } else if (j % 2 == 0 && ALT2[j] < n) {
            ALT2[j] = n;
        }
    }

    return j + 1;
}

int main() {

    cin >> NUMBERS;

    for (int i = 0; i < NUMBERS; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < NUMBERS; i++) {
        alt1[i] = alt1_fun(numbers[i]);
        alt2[i] = alt2_fun(numbers[i]);
    }
    stack<int> indexes;

    if (ALT_SIZE1 > ALT_SIZE2) {
        int current = (ALT_SIZE1 % 2 == 0 ? INT_MIN : INT_MAX);
        for (int i = NUMBERS - 1; i >= 0; i--) {
            if (alt1[i] != ALT_SIZE1) continue;
            if (ALT_SIZE1 % 2 == 0 && current < numbers[i]) {
                current = numbers[i];
                ALT_SIZE1--;
                indexes.push(i + 1);
            }

            if (ALT_SIZE1 % 2 == 1 && current > numbers[i]) {
                current = numbers[i];
                ALT_SIZE1--;
                indexes.push(i + 1);
            }
        }
    } else {
        int current = (ALT_SIZE2 % 2 == 0 ? INT_MAX : INT_MIN);
        for (int i = NUMBERS - 1; i >= 0; i--) {
            if (alt2[i] != ALT_SIZE2) continue;
            if (ALT_SIZE2 % 2 == 0 && current > numbers[i]) {
                current = numbers[i];
                ALT_SIZE2--;
                indexes.push(i + 1);
            }

            if (ALT_SIZE2 % 2 == 1 && current < numbers[i]) {
                current = numbers[i];
                ALT_SIZE2--;
                indexes.push(i + 1);
            }
        }
    }

    while (indexes.size()) {
        auto top = indexes.top();
        indexes.pop();
        cout << top;
        if (indexes.size()) cout << ' ';
    }
    cout << endl;

}