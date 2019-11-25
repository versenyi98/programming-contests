#include <iostream>

using namespace std;

int n;
string v[52];
bool touched[52];

int main() {

    while (cin >> n, n != 0) {
        string code, steps;
        int actual_index = -1;

        for (int i = 0; i < n; i++) {
            touched[i] = false;
        }

        for (int i = 0; i < n; i++) {
            cin >> code >> steps;

            for (int j = 0; j < steps.length(); j++) {
                
                actual_index++;
                actual_index = actual_index % n;

                while(touched[actual_index]) {
                    actual_index++;
                    actual_index = actual_index % n;
                }
            }
            touched[actual_index] = true;
            v[actual_index] = code;
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
}