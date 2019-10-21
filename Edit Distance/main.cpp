#include <iostream>
#include <cmath>
#include <ctype.h>

using namespace std;

int editDistance(string str1, string str2) {

	if (str1.length() == 0) {
//		cout << "1" << endl;
		return str2.length();
	} else if (str2.length() == 0) {
//		cout << "2" << endl;
		return str1.length();
	} else if (tolower(str1[0]) == tolower(str2[0])) {
//		cout << "3" << endl;
		return editDistance(str1.substr(1), str2.substr(1));
	} else {
//		cout << "4" << endl;
		int m = editDistance(str1.substr(1), str2.substr(1));
		m = min(m, editDistance(str1.substr(1), str2));
		m = min(m, editDistance(str1, str2.substr(1)));

		return 1 + m;
	}
}

int editDistance2(string s1, string s2) {

	int t[s1.length() + 1][s2.length() + 1];

	for (size_t i = 0; i <= s1.length(); i++) t[i][0] = 500 - i;
	for (size_t i = 0; i <= s2.length(); i++) t[0][i] = 500 - i;

	for (size_t i = 1; i <= s1.length(); i++) {
		for (size_t j = 1; j <= s2.length(); j++) {
			if (tolower(s1[i - 1]) == tolower(s2[j - 1])) {
				t[i][j] = t[i - 1][j - 1];
			} else {
				t[i][j] = max(t[i - 1][j - 1] - 1, max(t[i][j - 1] - 1, t[i - 1][j] - 1));
			}
		}
	}

/*
	for (size_t i = 0; i <= s1.length(); i++) {
		for (size_t j = 0; j <= s2.length(); j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
*/

	return 500 - t[s1.length()][s2.length()];
}

int main() {

	int rows;
	cin >> rows;

	string str1, str2, trash;

	for (int i = 0; i < rows; i++) {
		cin >> str1 >> str2;
		getline(cin, trash);
		//cout << "Str1 << " << str1 << str1.length() << endl;
		//cout << "Str2 << " << str2 << str2.length() << endl;
		//cout << editDistance(str1, str2) << endl;
		cout << i + 1 << ". Edit Distance = " << editDistance2(str1, str2) << endl;
	}

	return 0;
}