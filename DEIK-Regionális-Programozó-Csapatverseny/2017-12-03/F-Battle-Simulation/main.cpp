#include <iostream>
#include <set>

using namespace std;

int main() {

  string line;
  getline(cin, line);

  int i = 0;

  for (i = 0; i < (int)line.length() - 2; i++) {
    set <char> ch;

    ch.insert(line[i]);
    ch.insert(line[i + 1]);
    ch.insert(line[i + 2]);

    if (ch.size() == 3) {
      cout << "C";
      i += 2;
    } else {

      if (line[i] == 'R') {
        cout << "S";
      }

      if (line[i] == 'B') {
        cout << "K";
      }

      if (line[i] == 'L') {
        cout << "H";
      }
    }
  }

  if (i == line.length() - 2) {
    if (line[i] == 'R') {
      cout << "S";
    }

    if (line[i] == 'B') {
      cout << "K";
    }

    if (line[i] == 'L') {
      cout << "H";
    }

    i++;
  }

  if (i == line.length() - 1) {
    if (line[i] == 'R') {
      cout << "S";
    }

    if (line[i] == 'B') {
      cout << "K";
    }

    if (line[i] == 'L') {
      cout << "H";
    }
  }

  cout << endl;

  return 0;
}
