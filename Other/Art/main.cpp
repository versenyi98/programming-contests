#include <iostream>

using namespace std;

int t[5];

int valid(int a, int b, int c) {

    if (a + b <= c) {
        return 0;
    }

    if (b + c <= a) {
        return 0;
    } 

    if (c + a <= b) {
        return 0;
    }

    return 1;
}

int main() {

    int counter = 0;
    
    for (int i = 0; i < 5; i++) {
    	cin >> t[i];
    }

    for (int i = 0; i < 5; i++) { 
        for (int j = i+1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                counter += valid(t[i], t[j], t[k]);
            }
        }
    }
    
    cout << counter << endl;
}
