#include <iostream>

using namespace std;

int main() {

  int dimension, lines;

  while (cin >> dimension >> lines) {
    char draw[dimension][dimension];

    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        draw[i][j] = '.';
      }
    }

    int h, x, y;

    for (int i = 0; i < lines; i++) {
      cin >> h >> x >> y;

      //Stump
      if (h == 0) {

        if (y < 0 || y > dimension - 1) {
          continue;
        }

        if (x >= 0 && x <= dimension - 1) {
          draw[y][x] = 'o';
        }

        if (x - 1 >= 0 && x - 1 <= dimension - 1) {
          draw[y][x - 1] = '_';
        }

        if (x + 1 >= 0 && x + 1 <= dimension - 1) {
          draw[y][x + 1] = '_';
        }

      } else {

        if (y >= 0 && y <= dimension - 1) {
          //Root
          if (x >= 0 && x <= dimension - 1) {
            draw[y][x] = '|';
          }

          if (x - 1 >= 0 && x - 1 <= dimension - 1) {
            draw[y][x - 1] = '_';
          }

          if (x + 1 >= 0 && x + 1 <= dimension - 1) {
            draw[y][x + 1] = '_';
          }
        }
        //Trunk
        for (int j = 0; j < h; j++) {

          if (y + 1 + j >= 0 && y + 1 + j <= dimension - 1 && x >= 0 && x <= dimension - 1) {
            draw[y + 1 + j][x] = '|';
          }

          if (y + 1 + j >= 0 && y + 1 + j <= dimension - 1 &&  x - 1 >= 0 && x - 1 <= dimension - 1) {
            draw[y + 1 + j][x - 1] = '/';
          }

          if (y + 1 + j >= 0 && y + 1 + j <= dimension - 1 &&  x + 1 >= 0 && x + 1 <= dimension - 1) {
            draw[y + 1 + j][x + 1] = '\\';
          }
        }
        //Tree top
          if (y + 1 + h >= 0 && y + 1 + h <= dimension - 1 && x >= 0 && x <= dimension - 1) {
            draw[y + 1 + h][x] = '^';
          }
      }
    }

    //draw
    for (int i = 0; i < dimension + 2; i++) {
      cout << '*';
    }

    cout << endl;

      for (int j = 0; j < dimension; j++) {
        cout << '*';
        for (int k = 0; k < dimension; k++) {
          cout << draw[dimension - 1 - j][k];
        }
        cout << "*\n";
      }

    for (int i = 0; i < dimension + 2; i++) {
      cout << '*';
    }

    cout << endl << endl;
  }

}
