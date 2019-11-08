#include <iostream>

using namespace std;

int n, current;

int countLamps () {

    int count = 0;
    int i = 1;
    int j;

    while (current / (i * (i * 1)) - i - 1 > 0) {

        j = i + 1;

        while (current / (i * j) - j > 0) {
            //cout << i << " " << j << " " << current / (i * j) - j << endl;
            count += current / (i * j) - j;
            j++; 
        }
        i++;
    }

    return count;
}



int main() {

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> current;
        cout << countLamps() << endl;
    }
}