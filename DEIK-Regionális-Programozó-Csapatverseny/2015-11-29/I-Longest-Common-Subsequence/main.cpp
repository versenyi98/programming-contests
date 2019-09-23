#include <iostream>
#include <cmath>

using namespace std;

int lcss(string s1, string s2) {

	int maximum = 0;

	int t[s1.length() + 1][s2.length() + 1];

	for (size_t i = 0; i <= s1.length(); i++) t[i][0] = 0;
	for (size_t i = 0; i <= s2.length(); i++) t[0][i] = 0;

	for (size_t i = 1; i <= s1.length(); i++) {
		for (size_t j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				t[i][j] = t[i - 1][j - 1] + 1;
			} else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
			maximum = max(maximum, t[i][j]);
		}
	}

	return maximum;
}

int main() {

	string s1, s2;

	while(getline(cin, s1)) {
		getline(cin, s2);


		cout << lcss(s1, s2) << endl;
	}
}