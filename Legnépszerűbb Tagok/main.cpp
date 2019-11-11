#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int emberek[10000];
int kor_nagysaga[10000];
int erintes_datuma[10000];

int max_h = 0;
int eleje = 0;

void korbe(int aktual, int len, int jelen_erintes) {
	
	if (erintes_datuma[aktual - 1] == jelen_erintes) {
		if (len - kor_nagysaga[aktual - 1] > max_h) {
			max_h = len - kor_nagysaga[aktual - 1];
			eleje = aktual;
		}
		return;
	}

	kor_nagysaga[aktual - 1] = len;
	erintes_datuma[aktual - 1] = jelen_erintes;
	korbe(emberek[aktual - 1], len + 1, jelen_erintes);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> emberek[i];
		kor_nagysaga[i] = 0;
		erintes_datuma[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (erintes_datuma[i] == -1) {
			korbe(emberek[i], 0, i);
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
