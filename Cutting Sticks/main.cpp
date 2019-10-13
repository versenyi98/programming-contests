#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int table[52][52];
int points[52];

int distance(int i, int j) {
	return points[j]-points[i];
}


int mincut(int cuts) {

	for (int i = 0; i <= cuts + 1; i++) {
		for (int j = 0; j <= cuts + 1; j++) {
			table[i][j] = -1;
		}
	}

	for (int i = 0; i <= cuts; i++) {
		table[i][i + 1] = 0;
	}

	for (int i = 0; i <= cuts - 1; i++) {
		table[i][i + 2] = distance(i, i + 2);
	}

	for (int i = 3; i <= cuts + 1; i++) {
		for (int j = 0; j < cuts + 2 - i; j++) {

			for (int k = 1; k < i; k++) {
				if (table[j][i + j] == -1) {
					table[j][i + j] = table[j][i + j - k] + table[j + i - k][i + j] + distance(j, i + j);
				} else {
					table[j][i + j] = min(table[j][i + j], table[j][i + j - k] + table[j + i - k][i + j] + distance(j, i + j));
				}
			}
		}
	}
/*
	for (int i = 0; i <= cuts + 1; i++) {
		for (int j = 0; j <= cuts + 1; j++) {
			cout << table[i][j] << '\t';
		}
		cout << endl;
	}
*/
	return table[0][cuts + 1];
}


int main() {

	int length;
	int cuts;

	while (true) {
		scanf("%d", &length);
		if (length == 0) break;

		scanf("%d", &cuts);

		for (int i = 1; i <= cuts; i++) {
			scanf("%d", &points[i]);
		}
		points[0] = 0;
		points[cuts + 1] = length;

		printf("The minimum cutting is %d.\n", mincut(cuts));
	}

	return 0;
}
