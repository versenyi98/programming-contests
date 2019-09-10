#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

void floodFill(int img[][200], int brush, int i, int j, int height, int width, int target) {

  if (img[i][j] == brush || img[i][j] != target || i < 0 || j < 0 || i >= height || j >= width) return;
    img[i][j] = brush;

    floodFill(img, brush, i + 1, j, height, width, target);
    floodFill(img, brush, i - 1, j, height, width, target);
    floodFill(img, brush, i, j + 1, height, width, target);
    floodFill(img, brush, i, j - 1, height, width, target);

}

int findNeighbour(int img[][200], int i, int j, int di, int dj, int height, int width) {

	while (true) {

		if (i < 0 || j < 0 || i >= height || j >= width) break;

		if (img[i][j] > 0) {
			return img[i][j];
		}

		i += di;
		j += dj;
	}

	return -2;
}

int main() {

  char holesToSign[6];

  holesToSign[0] = 'W';
  holesToSign[1] = 'A';
  holesToSign[2] = 'K';
  holesToSign[3] = 'J';
  holesToSign[4] = 'S';
  holesToSign[5] = 'D';

  int n, m;
  int number = 0;
  int img[200][200];

  while (true) {
    cin >> n >> m;

    number++;

    if (n == 0 && m == 0) {
      return 0;
    }

//Handle input
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

        int l = 8;
        int hexa;

        scanf("%1x", &hexa);

        for (int k = 0; k < 4; k++) {
          img[i][j * 4 + k] = (hexa & l ? 1 : 0);
          l = l >> 1;
        }
      }
    }

//Flood signs to different colors
    int brush = 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m * 4; j++) {
        if (img[i][j] == 1) {
          floodFill(img, brush, i, j, n, m * 4, 1);
          brush++;
        }
      }
    }

    int holes[brush - 2];
    for (int i = 0; i < brush - 2; i++) {
      holes[i] = 0;
    }

//Flood background
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m * 4; j++) {
        if (img[i][j] == 0) {

          int a = findNeighbour(img, i, j, +1, 0, n, m * 4);
          int b = findNeighbour(img, i, j, -1, 0, n, m * 4);
          int c = findNeighbour(img, i, j, 0, +1, n, m * 4);
          int d = findNeighbour(img, i, j, 0, -1, n, m * 4);

          if (a < 0 || b < 0 || c < 0 || d < 0 || a != b || b != c || c != d) {
            floodFill(img, -1, i, j, n, m * 4, 0);
          }
        }
      }
    }
//Count holes for each sign
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m * 4; j++) {

        if (img[i][j] == 0) {
          int a = findNeighbour(img, i, j, 0, -1, n, m * 4);
	          holes[a - 2]++;
          floodFill(img, a, i, j, n, m * 4, 0);
        }
      }
    }

    string return_val = "";

    for (int i = 0; i < brush - 2; i++) {
      return_val += holesToSign[holes[i]];
    }

    std::sort(return_val.begin(), return_val.end());
    cout << "Case " << number << ": " + return_val << endl;

  }
}
