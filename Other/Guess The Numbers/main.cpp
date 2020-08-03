#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

int n;
int values[5];
int sum;

string operations;
string unique_;

bool is_zero[120];

vector<vector<int>> permutations;

int calculate(int index, string str);

int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n - 1) * n;
}


int main() {

    while (cin >> n, n != 0) {

        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        cin >> sum;
        cin >> operations;
        unique_ = "";

        for (int i = 0; i < operations.length(); i++) {
            if (isalpha(operations[i]) && unique_.find(operations[i]) == string::npos) {
                unique_ += operations[i];
            }
        }

        if (n == 5) {
            permutations = {
                {0, 1, 2, 3, 4},
                {0, 1, 2, 4, 3},
                {0, 1, 3, 2, 4},
                {0, 1, 3, 4, 2},
                {0, 1, 4, 2, 3},
                {0, 1, 4, 3, 2},
                {0, 2, 1, 3, 4},
                {0, 2, 1, 4, 3},
                {0, 2, 3, 1, 4},
                {0, 2, 3, 4, 1},
                {0, 2, 4, 1, 3},
                {0, 2, 4, 3, 1},
                {0, 3, 1, 2, 4},
                {0, 3, 1, 4, 2},
                {0, 3, 2, 1, 4},
                {0, 3, 2, 4, 1},
                {0, 3, 4, 1, 2},
                {0, 3, 4, 2, 1},
                {0, 4, 1, 2, 3},
                {0, 4, 1, 3, 2},
                {0, 4, 2, 1, 3},
                {0, 4, 2, 3, 1},
                {0, 4, 3, 1, 2},
                {0, 4, 3, 2, 1},
                {1, 0, 2, 3, 4},
                {1, 0, 2, 4, 3},
                {1, 0, 3, 2, 4},
                {1, 0, 3, 4, 2},
                {1, 0, 4, 2, 3},
                {1, 0, 4, 3, 2},
                {1, 2, 0, 3, 4},
                {1, 2, 0, 4, 3},
                {1, 2, 3, 0, 4},
                {1, 2, 3, 4, 0},
                {1, 2, 4, 0, 3},
                {1, 2, 4, 3, 0},
                {1, 3, 0, 2, 4},
                {1, 3, 0, 4, 2},
                {1, 3, 2, 0, 4},
                {1, 3, 2, 4, 0},
                {1, 3, 4, 0, 2},
                {1, 3, 4, 2, 0},
                {1, 4, 0, 2, 3},
                {1, 4, 0, 3, 2},
                {1, 4, 2, 0, 3},
                {1, 4, 2, 3, 0},
                {1, 4, 3, 0, 2},
                {1, 4, 3, 2, 0},
                {2, 0, 1, 3, 4},
                {2, 0, 1, 4, 3},
                {2, 0, 3, 1, 4},
                {2, 0, 3, 4, 1},
                {2, 0, 4, 1, 3},
                {2, 0, 4, 3, 1},
                {2, 1, 0, 3, 4},
                {2, 1, 0, 4, 3},
                {2, 1, 3, 0, 4},
                {2, 1, 3, 4, 0},
                {2, 1, 4, 0, 3},
                {2, 1, 4, 3, 0},
                {2, 3, 0, 1, 4},
                {2, 3, 0, 4, 1},
                {2, 3, 1, 0, 4},
                {2, 3, 1, 4, 0},
                {2, 3, 4, 0, 1},
                {2, 3, 4, 1, 0},
                {2, 4, 0, 1, 3},
                {2, 4, 0, 3, 1},
                {2, 4, 1, 0, 3},
                {2, 4, 1, 3, 0},
                {2, 4, 3, 0, 1},
                {2, 4, 3, 1, 0},
                {3, 0, 1, 2, 4},
                {3, 0, 1, 4, 2},
                {3, 0, 2, 1, 4},
                {3, 0, 2, 4, 1},
                {3, 0, 4, 1, 2},
                {3, 0, 4, 2, 1},
                {3, 1, 0, 2, 4},
                {3, 1, 0, 4, 2},
                {3, 1, 2, 0, 4},
                {3, 1, 2, 4, 0},
                {3, 1, 4, 0, 2},
                {3, 1, 4, 2, 0},
                {3, 2, 0, 1, 4},
                {3, 2, 0, 4, 1},
                {3, 2, 1, 0, 4},
                {3, 2, 1, 4, 0},
                {3, 2, 4, 0, 1},
                {3, 2, 4, 1, 0},
                {3, 4, 0, 1, 2},
                {3, 4, 0, 2, 1},
                {3, 4, 1, 0, 2},
                {3, 4, 1, 2, 0},
                {3, 4, 2, 0, 1},
                {3, 4, 2, 1, 0},
                {4, 0, 1, 2, 3},
                {4, 0, 1, 3, 2},
                {4, 0, 2, 1, 3},
                {4, 0, 2, 3, 1},
                {4, 0, 3, 1, 2},
                {4, 0, 3, 2, 1},
                {4, 1, 0, 2, 3},
                {4, 1, 0, 3, 2},
                {4, 1, 2, 0, 3},
                {4, 1, 2, 3, 0},
                {4, 1, 3, 0, 2},
                {4, 1, 3, 2, 0},
                {4, 2, 0, 1, 3},
                {4, 2, 0, 3, 1},
                {4, 2, 1, 0, 3},
                {4, 2, 1, 3, 0},
                {4, 2, 3, 0, 1},
                {4, 2, 3, 1, 0},
                {4, 3, 0, 1, 2},
                {4, 3, 0, 2, 1},
                {4, 3, 1, 0, 2},
                {4, 3, 1, 2, 0},
                {4, 3, 2, 0, 1},
                {4, 3, 2, 1, 0}};
        } else if (n == 4) {
            permutations = {
                {0, 1, 2, 3},
                {0, 1, 3, 2},
                {0, 2, 1, 3},
                {0, 2, 3, 1},
                {0, 3, 1, 2},
                {0, 3, 2, 1},
                {1, 0, 2, 3},
                {1, 0, 3, 2},
                {1, 2, 0, 3},
                {1, 2, 3, 0},
                {1, 3, 0, 2},
                {1, 3, 2, 0},
                {2, 0, 1, 3},
                {2, 0, 3, 1},
                {2, 1, 0, 3},
                {2, 1, 3, 0},
                {2, 3, 0, 1},
                {2, 3, 1, 0},
                {3, 0, 1, 2},
                {3, 0, 2, 1},
                {3, 1, 0, 2},
                {3, 1, 2, 0},
                {3, 2, 0, 1},
                {3, 2, 1, 0}};
        } else if (n == 3) {
            permutations = {
                {0, 1, 2},
                {0, 2, 1},
                {1, 0, 2},
                {1, 2, 0},
                {2, 0, 1},
                {2, 1, 0}};
        } else if (n == 2) {
            permutations = {
                {0, 1},
                {1, 0}
            };
        } else if (n == 1) {
            permutations = {{0}};
        }

        bool good = false;
        for (int i = 0; i < permutations.size(); i++) {
            is_zero[i] = false;
            int value = calculate(i, operations);

            if (!is_zero[i] && value == sum) {
                good = true;
                break;
            }
        }

        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int calculate(int index, string str) {
    if (str.length() == 1) {
        return values[permutations[index][unique_.find(str[0])]];
    }

    int brackets = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            brackets++;
            continue;
        } 
        if (str[i] == ')') {
            brackets--;
            continue;
        }

        if (brackets == 1 && !isalpha(str[i])) {
            string l = str.substr(1, i - 1);
            string r = str.substr(i + 1, str.length() - i - 2);

            int l_ = calculate(index, l);
            int r_ = calculate(index, r);

            if (str[i] == '+') {
                return l_ + r_;
            } else if (str[i] == '-') {
                return l_ - r_;
            } else if (str[i] == '*') {
                return l_ * r_;
            } else if (str[i] == '/') {
                if (l_ == 0) {
                    l_ = 1;
                    is_zero[index] = true;
                }
                return l_ / r_;
            }
        }
    }
}