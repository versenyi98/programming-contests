#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {

  int rows;
  int columns;

  string line;
  string word = "saba";
  int len = 4;

  cin >> rows;
  cin >> columns;

  getline(cin, line);

  char table[max(rows, columns)+4][max(rows,columns)+4];

  for (int i = 0; i < max(rows, columns) + 4; i++) {
    for (int j = 0; j < max(rows, columns) + 4; j++) {
      table[i][j] = ' ';
    }
  }

  for (int i = 0; i < rows; i++) {
    getline(cin, line);
    for (int j = 0; j < columns; j++) {
      table[i][j] = line[j];
    }
  }

/*
  for (int i = 0; i < max(rows, columns) + 4; i++) {
    for (int j = 0; j < max(rows, columns) + 4; j++) {
      cout << table[i][j] << ".";
    }
    cout << endl;
  }
*/

  int counter = 0;
  for (int i = 0; i < max(rows, columns); i++) {
    for (int j = 0; j < max(rows, columns); j++) {
      int counter1 = 0;
      int counter2 = 0;
      int counter3 = 0;
      int counter4 = 0;
      for (int k = 0; k < len; k++) {
        if (counter1 == k && table[i][j + k] == word[k]) {
          counter1++;
        }

        //cout << table[j + k][i];
        if (counter2 == k && table[j + k][i] == word[k]) {
          counter2++;
        }

        //cout << table[i + k][j + k];
        if (counter3 == k && table[i + k][j + k] == word[k]) {
          counter3++;
        }
        int x = rows + 2 - k - i;
        int y =  j + k;
        //cout << table[x][y];
        //cout << x << " " << y << "\t";
        if (counter4 == k && table[x][y] == word[k]) {
          counter4++;
        }
      }
      //cout << endl;
      counter += (counter1 == 4);
      counter += (counter2 == 4);
      counter += (counter3 == 4);
      counter += (counter4 == 4);
    }
  }
  cout << counter << endl;
}
