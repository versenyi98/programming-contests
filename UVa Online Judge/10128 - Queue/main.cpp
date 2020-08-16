#include <bits/stdc++.h>

using namespace std;

map<pair<int, pair<int, int>>, uint64_t> precalced;

uint64_t factorial(int n) {
	if (n) return n * factorial(n - 1);
	return 1;
}

int main() {

	// Precalc
	for (int i = 1; i <= 13; i++) {
		map<pair<int, pair<int, int>>, uint64_t> mapping;

		vector<int> v;
		for (int j = 0; j < i; j++) {
			v.push_back(j + 1);
		}

		for (uint64_t j = 0; j < factorial(i); j++) {
			int from_start = 0, from_start_val = 0;
			int from_end = 0, from_end_val = 0;

			for (int k = 0; k < i; k++) {
				if (v[k] > from_start_val) {
					from_start++;
					from_start_val = v[k];
				}	
			}
			
			for (int k = i - 1; k >= 0; k--) {
				if (v[k] > from_end_val) {
					from_end++;
					from_end_val = v[k];
				}
			}

			mapping[{i, {from_start, from_end}}]++;

			next_permutation(v.begin(), v.end());
		}
		
		for (auto i : mapping) {
		cout << "\tprecalced[{" << i.first.first << ", {" << i.first.second.first << ", " << i.first.second.second << "}}] = " << i.second << ";" << endl;;
		}
	}
	return 0;

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, n1, n2;
		cin >> n >> n1 >> n2;
		cout << precalced[{n, {n1, n2}}] << endl;
	}


	return 0;
}