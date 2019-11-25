#include <iostream>

using namespace std;

int hangyak, hossz;

int main() {

	while (cin >> hossz >> hangyak, hossz != 0 && hangyak != 0) {

		int start;
		char irany;
		int maximum = 0;

		for (int i = 0; i < hangyak; i++) {
			cin >> start >> irany;

			if (irany == 'R') {
				maximum = max(maximum, hossz - start);
			} else {
				maximum = max(maximum, start);
			}
		}

		cout << "The last ant will fall down in " << maximum << " seconds.\n";
	}
}