#include <iostream>

using namespace std;

int main() {

	int n;

	while (cin >> n, n!=0) {
		if (n == 2) {
			cout << "Bad luck!\n";
		} else {
			cout << "Electrician needs 1 trips.\n";
		}
	}
}