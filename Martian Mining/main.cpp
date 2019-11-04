#include <iostream>

using namespace std;

int bloggium[500][500];
int yeayenum[500][500];

int dn[500][500];
int n, m;

int main() {

	while (scanf("%d %d", &n, &m), n != 0) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &yeayenum[i][j]);
				if (j) yeayenum[i][j] += yeayenum[i][j - 1];
			}
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &bloggium[0][i]);
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &bloggium[i][j]);
				bloggium[i][j] += bloggium[i - 1][j];
			}
		}

		dn[0][0] = max(bloggium[0][0], yeayenum[0][0]);

		for (int i = 1; i < n; i++) {
			dn[0][i] = max(dn[0][i - 1] + bloggium[0][i], yeayenum[0][i]);
		}

		for (int i = 1; i < m; i++) {
			dn[i][0] = max(yeayenum[i][0] + dn[i - 1][0], bloggium[i][0]);
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dn[i][j] = max(bloggium[i][j] + dn[i][j - 1], yeayenum[i][j] + dn[i - 1][j]);
			}
		}

		printf("%d\n", dn[n - 1][m - 1]);
	}
}
