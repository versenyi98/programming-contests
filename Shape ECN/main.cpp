#include <iostream>
#include <cmath>
#include <ctype.h>
#include <vector>

using namespace std;

int editDistance(string s1, string s2) {

	int t[s1.length() + 1][s2.length() + 1];

	int s1_length = s1.length();
	int s2_length = s2.length();

	for (int i = 0; i <= s1_length; i++) t[i][0] = - i;
	for (int i = 0; i <= s2_length; i++) t[0][i] = - i;

	for (int i = 1; i <= s1_length; i++) {
		for (int j = 1; j <= s2_length; j++) {
			if (tolower(s1[i - 1]) == tolower(s2[j - 1])) {
				t[i][j] = t[i - 1][j - 1];
			} else {
				t[i][j] = max(t[i - 1][j - 1] - 1, max(t[i][j - 1] - 1, t[i - 1][j] - 1));
			}
		}
	}

	return -t[s1.length()][s2.length()];
}

string push(string str, int n) {

	for (int i = 0; i < str.length(); i++) {

		int new_char = ((int)str[i] - 'A' + n) % 26;
		str[i] = 'A' + new_char;
	}

	return str;
}
int main() {

	vector<string> v;
	int lines;
	cin >> lines;

	for (int i = 0; i < lines; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	int edit_dist = editDistance(v[0], "ECN");
	v[0] = "ECN";

	int return_value = 1;

	int v_size = v.size();
	for (int i = 1; i < v_size; i++) {
		int new_edit_dist = editDistance(v[i], push(v[i - 1], edit_dist));
		v[i] = push(v[i - 1], edit_dist);
		return_value += (v[i].compare("ECN") == 0);
		
		edit_dist = new_edit_dist;
	}

	cout << return_value << endl;

	
	return 0;
}