#include <bits/stdc++.h>

using namespace std;


int main() {

	string hori[5] = {
		"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
		"*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
		"*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
		"....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
		"*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."
	};

	string vert[66] = {
		"*****",
		"*....",
		"*****",
		"....*",
		"*****",
		".....",
		".***.",
		"*...*",
		"*****",
		"*...*",
		"*...*",
		".....",
		"*...*",
		"*...*",
		"*...*",
		".*.*.",
		"..*..",
		".....",
		"*****",
		"*....",
		"***..",
		"*....",
		"*****",
		".....",
		".....",
		".....",
		"*...*",
		"*...*",
		"*****",
		"*...*",
		"*...*",
		".....",
		"*****",
		"*...*",
		"*****",
		"*.*..",
		"*..**",
		".....",
		"*****",
		"..*..",
		"..*..",
		"..*..",
		"*****",
		".....",
		"***..",
		"*..*.",
		"*...*",
		"*..*.",
		"***..",
		".....",
		"*****",
		"*...*",
		"*...*",
		"*...*",
		"*****",
		".....",
		"*...*",
		".*.*.",
		"..*..",
		"..*..",
		"..*.."
	};

	int n;
	while (scanf("%d", &n), n) {

		bool vertical = n < 0;
		n = abs(n);

		if (!vertical) {
			for (int i = 0; i < 5; i++) {
				for (int ii = 0; ii < n; ii++) {
					for (int j = 0; j < 61; j++) {
						for (int jj = 0; jj < n; jj++) {
							putchar(hori[i][j]);
						}
					}
					putchar('\n');
				}
			}
		} else {
			for (int i = 0; i < 61; i++) {
				for (int ii = 0; ii < n; ii++) {
					for (int j = 0; j < 5; j++) {
						for (int jj = 0; jj < n; jj++) {
							putchar(vert[i][j]);
						}
					}
					putchar('\n');
				}
			}
		}

		putchar('\n'); putchar('\n');
	}

	return 0;
}