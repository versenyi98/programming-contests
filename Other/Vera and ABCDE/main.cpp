#include <iostream>

using namespace std;

char solution[5][6051];
char ch;

void draw(int i) {

    if (ch == 'A') {
        solution[0][i*3] = '*';
        solution[0][i*3 + 1] = '*';
        solution[0][i*3 + 2] = '*';

        solution[1][i*3] = '*';
        solution[1][i*3 + 1] = '.';
        solution[1][i*3 + 2] = '*';

        solution[2][i*3] = '*';
        solution[2][i*3 + 1] = '*';
        solution[2][i*3 + 2] = '*';

        solution[3][i*3] = '*';
        solution[3][i*3 + 1] = '.';
        solution[3][i*3 + 2] = '*';

        solution[4][i*3] = '*';
        solution[4][i*3 + 1] = '.';
        solution[4][i*3 + 2] = '*';  

    } else if (ch == 'B') {
        solution[0][i*3] = '*';
        solution[0][i*3 + 1] = '*';
        solution[0][i*3 + 2] = '*';

        solution[1][i*3] = '*';
        solution[1][i*3 + 1] = '.';
        solution[1][i*3 + 2] = '*';

        solution[2][i*3] = '*';
        solution[2][i*3 + 1] = '*';
        solution[2][i*3 + 2] = '*';

        solution[3][i*3] = '*';
        solution[3][i*3 + 1] = '.';
        solution[3][i*3 + 2] = '*';

        solution[4][i*3] = '*';
        solution[4][i*3 + 1] = '*';
        solution[4][i*3 + 2] = '*';  
    } else if (ch == 'C') {
        solution[0][i*3] = '*';
        solution[0][i*3 + 1] = '*';
        solution[0][i*3 + 2] = '*';

        solution[1][i*3] = '*';
        solution[1][i*3 + 1] = '.';
        solution[1][i*3 + 2] = '.';

        solution[2][i*3] = '*';
        solution[2][i*3 + 1] = '.';
        solution[2][i*3 + 2] = '.';

        solution[3][i*3] = '*';
        solution[3][i*3 + 1] = '.';
        solution[3][i*3 + 2] = '.';

        solution[4][i*3] = '*';
        solution[4][i*3 + 1] = '*';
        solution[4][i*3 + 2] = '*';  
    } else if (ch == 'D') {
        solution[0][i*3] = '*';
        solution[0][i*3 + 1] = '*';
        solution[0][i*3 + 2] = '*';

        solution[1][i*3] = '*';
        solution[1][i*3 + 1] = '.';
        solution[1][i*3 + 2] = '*';

        solution[2][i*3] = '*';
        solution[2][i*3 + 1] = '.';
        solution[2][i*3 + 2] = '*';

        solution[3][i*3] = '*';
        solution[3][i*3 + 1] = '.';
        solution[3][i*3 + 2] = '*';

        solution[4][i*3] = '*';
        solution[4][i*3 + 1] = '*';
        solution[4][i*3 + 2] = '*';  
    } else if (ch == 'E') {
        solution[0][i*3] = '*';
        solution[0][i*3 + 1] = '*';
        solution[0][i*3 + 2] = '*';

        solution[1][i*3] = '*';
        solution[1][i*3 + 1] = '.';
        solution[1][i*3 + 2] = '.';

        solution[2][i*3] = '*';
        solution[2][i*3 + 1] = '*';
        solution[2][i*3 + 2] = '*';

        solution[3][i*3] = '*';
        solution[3][i*3 + 1] = '.';
        solution[3][i*3 + 2] = '.';

        solution[4][i*3] = '*';
        solution[4][i*3 + 1] = '*';
        solution[4][i*3 + 2] = '*';  
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        draw(i);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n * 3; j++) {
            cout << solution[i][j];
        }
        cout << endl;
    }
}