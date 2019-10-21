#include <iostream>

using namespace std;

int main() {

  int n;

  while (cin >> n) {
    if (n == 0) break;

    char spiral[n][n];

    string str;
    getline(cin, str);
    getline(cin, str);

    for (int i = str.length(); i < n*n; i++) {
      str = str + " ";
    }

    int moves[4] = {+1, -n, -1, +n};
    int moveCount = 0;
    int starter = n*n-n-1;
    int saved = n*2;
    int index = 0;

    while(saved >= 0) {
      for (int i = 0; i < saved/2; i++) {
        starter+=moves[moveCount%4];
        spiral[starter/n][starter%n] = str[index];
        index++;
      }
      saved--;
      moveCount++;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << spiral[i][j];
      }
      cout << endl;
    }
    cout << endl;
    getline(cin, str);
  }
}
