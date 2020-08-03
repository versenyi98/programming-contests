#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> negatives;
int moves = 0;
int aktual = 0;

int main() {

	int n;
	cin >> n;

	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		numbers.push_back(temp);
		if (temp < 0) {
			negatives.push_back(i);
		}
	}

	while (aktual < negatives.size()) {

		int next = negatives[aktual] + 1;
		int prev = negatives[aktual] - 1;

		if (prev < 0) prev = n - 1;
		if (next == n) next = 0;

		if (numbers[negatives[aktual]] >= 0) {
			aktual++;
			continue;
		}

		numbers[negatives[aktual]] *= -1;
		numbers[prev] -= numbers[negatives[aktual]];
		numbers[next] -= numbers[negatives[aktual]];

		if (numbers[next] < 0) negatives.push_back(next);
		if (numbers[prev] < 0) negatives.push_back(prev);

		moves++;
		aktual++;
	}
	cout << moves << endl;
}
