#include <iostream>
#include <vector>

using namespace std;

int main() {

  int rows;
  while(cin >> rows) {
    if (rows == 0) break;

    string line;
    vector<string> table, words;

    for (int i = 0; i < rows; i++) {
      cin >> line;
      table.push_back(line);
    }
    int wordsCount;
    cin >> wordsCount;
    for (int i = 0; i < wordsCount; i++) {
      cin >> line;
      words.push_back(line);
    }
    for (int i = 0; i < words.size(); i++) {

      bool b1, b2, b3, b4;

      b1 = false;
      b2 = false;
      b3 = false;
      b4 = false;

      int n = words[i].length();

      for (int j = 0; j < rows; j++) {
        for (int k = 0; k < rows - n + 1; k++) {
          int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
          for (int l = 0; l < words[i].length(); l++) {
            if (c1 == l && table[j][k + l] == words[i][l]) {
              c1++;
            } if (c2 == l && table[k + l][j] == words[i][l]) {
              c2++;
            } if (c3 == l && table[j][k + l] == words[i][words[i].length() - 1 - l]) {
              c3++;
            } if (c4 == l && table[k + l][j] == words[i][words[i].length() - 1 - l]) {
              c4++;
            }
          }

          if (c1 == words[i].length()) {
            cout << words[i] << ' ' << k + 1 << ' ' << j + 1 << ' ' << "R" << endl;
            b1 = true;
          } else if (c2 == words[i].length()) {
            cout << words[i] << ' ' << j + 1 << ' ' << k + 1 << ' ' << "D" << endl;
            b2 = true;
          } else if (c3 == words[i].length()) {
            cout << words[i] << ' ' << k + words[i].length() << ' ' << j + 1 << ' ' << "L" << endl;
            b3 = true;
          } else if (c4 == words[i].length()) {
            cout << words[i] << ' ' << j + 1 << ' ' << k + words[i].length() << ' ' << "U" << endl;
            b4 = true;
          }
        }
      }
      if(!(b1 || b2 || b3 || b4)) {
        cout << words[i] << " WAS NOT FOUND" << endl;
      }
    }
    cout << endl;
  }
}
