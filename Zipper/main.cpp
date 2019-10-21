#include <iostream>
#include <cstdlib>

using namespace std;

string a, b, c;
bool t[201][201];

bool zipper(int i, int j) {

	if (t[i][j]) {
		return true;
	}

	if (!i && b[j - 1] == c[j - 1]) {
		t[i][j] = zipper(i, j - 1);
		return t[i][j];
	}

	if (!j && a[i - 1] == c[i - 1]) {
		t[i][j] = zipper(i - 1, j);
		return t[i][j];
	}

	if (!i && b[j - 1] != c[j - 1]) {
		return false;
	}

	if (!j && a[i - 1] != c[i - 1]) {
		return false;
	}

	t[i][j] = (a[i - 1] == c[i + j - 1] && zipper(i - 1, j)) || 
						(b[j - 1] == c[i + j - 1] && zipper(i, j - 1));

	return t[i][j];
}


int main() {

  int test_cases;
  scanf("%d\n", &test_cases);

  for (int i = 0; i < test_cases; i++) {
    cin >> a >> b >> c;


		for (int i = 0; i < a.length() + 1; i++) {
			for (int j = 0; j < b.length() + 1; j++) {
				t[i][j] = false;
			}
		}
		t[0][0] = true;

    printf("Data set %d: %s\n", i + 1, ((zipper(a.length(), b.length()) ? "yes" : "no")));
  }

  return 0;
}
