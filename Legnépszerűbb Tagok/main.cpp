#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int emberek[10000];
bool eritve[10000];
int ertek[10000];
int korok[10000];

int max_h = 0;
int eleje = 0;

int kor = -1;

void korbe(int aktual, int len) {
	
	if (korok[aktual - 1] != 0) {
		return;
	}

	if (eritve[aktual - 1]) {
		if (len - ertek[aktual - 1] > max_h) {
			max_h = len - ertek[aktual - 1];
			eleje = aktual;
		}
		kor = len - ertek[aktual - 1];
		korok[aktual - 1] = kor;
		return;
	}

	ertek[aktual - 1] = len;
	eritve[aktual - 1] = true;
	korbe(emberek[aktual - 1], len + 1);

	if (kor > 0) {
		if (korok[aktual - 1] > 0) {
			kor = -1;
			return;
		}
		korok[aktual - 1] = kor;
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> emberek[i];
		korok[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (!eritve[i]) {
			korbe(emberek[i], 0);
		}
	}

	cout << max_h << endl;
	for (int i = 0; i < max_h; i++) {
		if (i)  cout << " ";
		cout << eleje;
		eleje = emberek[eleje - 1];
	}
	cout << endl;
}
