#include <iostream>

using namespace std;

int n, m;
int lines;

bool magic(long long num) {

	if (num > n || num > m) return false;
	if (n % num == 0 && m % num == 2) return true;
	if (m % num == 0 && n % num == 2) return true;
	if (n % num == 0 && (m - 2) % num == 0) return true;
	if (m % num == 0 && (n - 2) % num == 0) return true;
	if ((n - 1) % num == 0 && (m - 1) % num == 0) return true; 
	if (n % num == 1 && m % num == 0 && (m - 2) % num == 0) return true;
	if (m % num == 1 && n % num == 0 && (n - 2) % num == 0) return true;
	return false;
}

int main() {
	cin >> n >> m >> lines;

	long long  case_;
	for (long long i = 0; i < lines; i++) {
		cin >> case_;
		cout << (magic(case_) ? "YES" : "NO") << endl;
	}
}
