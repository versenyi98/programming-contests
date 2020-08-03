#include <iostream>

using namespace std;

int tesztesetek;
int hossz_1, szelesseg_1;
int hossz_2, szelesseg_2;

char matrix_1[100][100];
char matrix_2[100][100];

pair<int, int> start[100000];
int start_meret = 0;

bool egyezik(int x1, int y1, int x2, int y2, int count) {
//    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
//    cout << matrix_1[y1][x1] << " " << matrix_2[y2][x2] << endl;
    if (count == hossz_1 * szelesseg_1) return true;

    if (matrix_1[y1][x1] == matrix_2[y2][x2]) {
        return egyezik(
            (x1 + 1) % szelesseg_1,
            (y1 + (x1 + 1) / szelesseg_1),
            (x1 + 1) % szelesseg_1 == 0 ? (x2 + 1 - szelesseg_1 + szelesseg_2) % szelesseg_2: (x2 + 1) % szelesseg_2,
            (y2 + (x1 + 1) / szelesseg_1) % hossz_2,
            count + 1
        );
    }

    return false;
}

int main() {

    cin >> tesztesetek;

    for (int m = 0; m < tesztesetek; m++) {
        start_meret = 0;
        cin >> hossz_1 >> szelesseg_1;

        for (int i = 0; i < hossz_1; i++) {
            for (int j = 0; j < szelesseg_1; j++) {
                cin >> matrix_1[i][j];
            }
        }

        cin >> hossz_2 >> szelesseg_2;
    
        for (int i = 0; i < hossz_2; i++) {
            for (int j = 0; j < szelesseg_2; j++) {
                cin >> matrix_2[i][j];
                if (matrix_2[i][j] == matrix_1[0][0]) {
                    start[start_meret] = {i, j};
                    start_meret++;
                }
            }
        }

        cout << "#" << m + 1 << endl;
        bool first_ = true;
        for (int i = 0; i < start_meret; i++) {
            if (egyezik(0, 0, start[i].second, start[i].first, 0)) {
                if (!first_) cout << " ";
                first_ = false;
                cout << "(" << start[i].first << "," << start[i].second << ")";
            }
        }
        cout << endl;
    }

}