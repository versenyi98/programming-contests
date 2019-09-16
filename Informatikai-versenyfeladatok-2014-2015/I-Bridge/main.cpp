#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	int tesztesetek;

	cin >> tesztesetek;
	string str;

	getline(cin, str);

	for (int i = 0; i < tesztesetek; i++) {
		vector<int> v;
		getline(cin, str);

		int n, number;
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> number;
			v.push_back(number);
		}

		sort(v.begin(), v.end());

		int li = v.size() - 1;

		string result = "";
		int result_sec = 0;

		while (li > 2) {
			if (2 * v[1] < v[li - 1] + v[0]) {
				result_sec += 2 * v[1] + v[0] + v[li];

				result += to_string(v[0]) + " " + to_string(v[1]) + "\n";
				result += to_string(v[0]) + "\n";
				result += to_string(v[li - 1]) + " " + to_string(v[li]) + "\n";
				result += to_string(v[1]) + "\n";
				li -= 2;
			} else {
				result_sec += 2 * v[0] + v[li - 1] + v[li];

				result += to_string(v[0]) + " " + to_string(v[li]) + "\n";
				result += to_string(v[0]) + "\n";
				result += to_string(v[0]) + " " + to_string(v[li - 1]) + "\n";
				result += to_string(v[0]) + "\n";
				li -= 2;
			}
		}

		if (li == 2) {
			result_sec += v[0] + v[1] + v[2];

			result += to_string(v[0]) + " " + to_string(v[2]) + "\n";
			result += to_string(v[0]) + "\n";
			result += to_string(v[0]) + " " + to_string(v[1]) + "\n";
		} else if (li == 1) {
			result_sec += v[1];

			result += to_string(v[0]) + " " + to_string(v[1]) + "\n";
		} else if (li == 0) {
			result_sec += v[0];

			result += to_string(v[0]) + "\n";
		}

		cout << result_sec << endl << result << endl;


	}
}
