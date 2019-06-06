#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

  int rows, columns;

  cin >> rows >> columns;
  int width = columns * 4 + 1 + rows * 2;
  int height = 0;

  int field[rows][columns];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> field[i][j];
      height = max(height, (field[i][j] - 1) * 3 + 6 + (rows - i - 1) * 2);
    }
  }

  char cubes[height][width];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cubes[i][j] = '.';
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {

      for (int k = 0; k < field[i][j]; k++) {
        int vertical, horizontal;
        vertical = (rows - 1 - i) * 2 + k * 3;
        horizontal = (rows - 1 - i) * 2 + j * 4;

        cubes[vertical][horizontal] = '+';
        cubes[vertical][horizontal + 1] = '-';
        cubes[vertical][horizontal + 2] = '-';
        cubes[vertical][horizontal + 3] = '-';
        cubes[vertical][horizontal + 4] = '+';

        cubes[vertical + 3][horizontal] = '+';
        cubes[vertical + 3][horizontal + 1] = '-';
        cubes[vertical + 3][horizontal + 2] = '-';
        cubes[vertical + 3][horizontal + 3] = '-';
        cubes[vertical + 3][horizontal + 4] = '+';

        cubes[vertical + 4][horizontal + 1] = '/';
        cubes[vertical + 4][horizontal + 5] = '/';
        cubes[vertical + 1][horizontal + 5] = '/';

        cubes[vertical + 2][horizontal + 6] = '+';
        cubes[vertical + 3][horizontal + 6] = '|';
        cubes[vertical + 4][horizontal + 6] = '|';

        for (int l = 0; l < 2; l++) {
          for (int m = 0; m < 3; m++) {
            cubes[vertical + 1 + l][horizontal + 1 + m] = ' ';
          }
        }

        cubes[vertical + 4][horizontal + 2] = ' ';
        cubes[vertical + 4][horizontal + 3] = ' ';
        cubes[vertical + 4][horizontal + 4] = ' ';

        cubes[vertical + 2][horizontal + 5] = ' ';
        cubes[vertical + 3][horizontal + 5] = ' ';

        cubes[vertical + 5][horizontal + 2] = '+';
        cubes[vertical + 5][horizontal + 3] = '-';
        cubes[vertical + 5][horizontal + 4] = '-';
        cubes[vertical + 5][horizontal + 5] = '-';
        cubes[vertical + 5][horizontal + 6] = '+';

        cubes[vertical + 1][horizontal] = '|';
        cubes[vertical + 2][horizontal] = '|';
        cubes[vertical + 1][horizontal + 4] = '|';
        cubes[vertical + 2][horizontal + 4] = '|';
      }
    }
  }


  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << cubes[height - 1 - i][j];
    }
    cout << endl;
  }

  return 0;
}
