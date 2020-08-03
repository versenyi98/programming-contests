#include <iostream>

using namespace std;

int wh[1000][1000];
int bl[1000][1000];
int tb[1000][1000];
int dn[1000][1000];

int sz;

int main() {

	cin >> sz;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cin >> tb[i][j];
		}
	}

	for (int i = 0; i < sz; i++) {
		bl[i][sz - 1] = tb[i][sz - 1] == 0;
		wh[sz - 1][i] = tb[sz - 1][i] == 1;
		for (int j = sz - 2; j >= 0; j--) {
			bl[i][j] = bl[i][j + 1] + (tb[i][j] == 0);
			wh[j][i] = wh[j + 1][i] + (tb[j][i] == 1);
		}
	}

	for (int i = 0; i < sz; i++) {
		dn[sz - 1][i] = 0;
		dn[i][sz - 1] = 0;
	}

	for (int i = sz - 2; i >= 0; i--) {
		for (int j = sz - 2; j >= 0; j--) {
			dn[i][j] = min(	dn[i + 1][j] + bl[i][j + 1],
							dn[i][j + 1] + wh[i + 1][j]);
		}
	}
/*	
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << dn[i][j] << " ";
		}
		cout << endl;
	}
*/	
	cout << dn[0][0] << endl;

}