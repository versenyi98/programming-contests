#include <iostream>
#include <ctype.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	string str;
	getline(cin, str);

	bool first_ = true;

	for (int i = 0; i < n; i++) {
		getline(cin, str);

		int count = 0;
		int F1 = 0, F2 = 0, M1 = 0, M2 = 0;
		bool first_ = true;
		
		for (int j = 0; j < str.length(); j++) {

			if (isspace(str[j])) {
				first_ = true;
				continue;
			}

			if (str[j] == 'F') {

				if (first_) {
					F1++;
				} else {
					F2++;
					count++;
				}

				first_ = false;
			} else if (str[j] == 'M') {

				if (first_) {
					M1++;
				} else {
					M2++;
					count++;
				}

				first_ = false;
			}
		}

		if (F1 == M2 && M1 == F2 && count > 1) {
			cout << "LOOP\n";
		} else {
			cout << "NO LOOP\n";
		}
	}

	return 0;
}