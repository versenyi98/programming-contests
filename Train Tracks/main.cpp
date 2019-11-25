#include <iostream>
#include <ctype.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	string str;
	getline(cin, str);

	for (int i = 0; i < n; i++) {
		getline(cin, str);

		int MM = 0, FF = 0, MF = 0, FM = 0;
		char first_letter;
		bool first_ = true;

		for (int j = 0; j < str.length(); j++) {

			if (isspace(str[j])) {
				first_ = true;
				continue;
			}

			if (str[j] == 'F') {

				if (first_) {
					first_letter = 'F';
				} else {
					if (first_letter == 'F') {
						FF++;
					} else {
						MF++;
					}
				}

				first_ = false;
			} else if (str[j] == 'M') {

				if (first_) {
					first_letter = 'M';
				} else {
					if (first_letter == 'M') {
						MM++;
					} else {
						FM++;
					}
				}

				first_ = false;
			}
		}
		if (MM + FF + FM == 0 && MF > 1) {
			cout << "LOOP\n";
		} else if (MM + FF + MF == 0 && FM > 1) {
			cout << "LOOP\n";
		} else if (MM == FF && MM > 0) {
			cout << "LOOP\n";
		} else {
			cout << "NO LOOP\n";
		}
		//cout << FF << " " << MM << " " << MF << " " << FM << endl ;
	}

	return 0;
}
