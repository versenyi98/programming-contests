#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<string> v) {

  int counter = 0;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].length(); j++) {
      counter += v[i][j] == 'k';
    }
  }

  if (counter != 9) return false;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].length(); j++) {
      if (v[i][j] == 'k') {

        if (i - 2 >= 0 && j - 1 >= 0 && v[i - 2][j - 1] == 'k') return false;
        if (i - 1 >= 0 && j - 2 >= 0 && v[i - 1][j - 2] == 'k') return false;
        if (i - 2 >= 0 && j + 1 <= 4 && v[i - 2][j + 1] == 'k') return false;
        if (i - 1 >= 0 && j + 2 <= 4 && v[i - 1][j + 2] == 'k') return false;

        if (i + 2 <= 4 && j - 1 >= 0 && v[i + 2][j - 1] == 'k') return false;
        if (i + 1 <= 4 && j - 2 >= 0 && v[i + 1][j - 2] == 'k') return false;
        if (i + 2 <= 4 && j + 1 >= 0 && v[i + 2][j + 1] == 'k') return false;
        if (i + 1 <= 4 && j + 2 >= 0 && v[i + 1][j + 2] == 'k') return false;

      }
    }
  }

  return true;
}


int main() {

  string str;
  vector<string> v;

  for (int i = 0; i < 5; i++) {
    cin >> str;
    v.push_back(str);
  }

  if (isValid(v)) {
    cout << "valid" << endl;
  } else {
    cout << "invalid" << endl;
  }

}
