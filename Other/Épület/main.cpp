#include <iostream>

using namespace std;

int n;

int main() {

	while (cin >> n) {

		unsigned long long f = 1, p = 1, z  = 1;
		unsigned long long nf = 0, np = 0, nz = 0;

		while (--n) {
			nf = (f + p + z) % 20160109;
			np = (f + z) % 20160109;
			nz = f;

			f = nf;
			p = np;
			z = nz;
		}

		cout << (f + p + z) % 20160109 << endl;
	}

	return 0;
}