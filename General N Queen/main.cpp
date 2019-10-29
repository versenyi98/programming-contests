#include <iostream>
#include <cmath>

using namespace std;

int table[15];

bool validQueen(int n) {

    for (int i = 0; i < n; i++) {
        if (table[i] != -1) {
            for (int j = i + 1; j < n; j++) {
                if (table[j] == -1) continue;
                if (table[i] == table[j]) return false;
                if (abs(table[i] - table[j]) == j - i) return false;
            }
        }
    }

    return true;
}

int countQueen(int n) {

    int values[n];
    for (int i = 0; i < n; i++) {
        table[i] = -1;
        values[i] = 0;
    }

    int validCounter = 0;
    int actual = 0;
    
    while (true) {

        table[actual] = values[actual];

        if (validQueen(n)) {
            if (actual == n - 1) {
                validCounter++;
                while (true) {

                    if (values[actual] == n - 1) {
                        values[actual] = 0;
                        table[actual] = -1;
                        actual--;
                    } else {
                        values[actual]++;
                        break;
                    }

                    if (actual == -1) {
                        return validCounter;
                    }
                }
            } else {
                actual++;
            }
            
        } else {
            while (true) {
                if (values[actual] == n - 1) {
                    values[actual] = 0;
                    table[actual] = -1;
                    actual--;
                } else {
                    values[actual]++;
                    break;
                }
                if (actual == -1) {
                    return validCounter;
                }
            }
        }
    }
}


int main() {
    for (int i = 2; i <= 13; i++) {
        cout << i << "\t=>\t" << countQueen(i) << endl;

    }



}