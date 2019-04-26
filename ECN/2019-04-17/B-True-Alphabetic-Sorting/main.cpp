#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

int main() {

  string temp;

  while (cin >> temp) {
    if (temp.compare("END") == 0) break;

    sort(temp.begin(), temp.end(), [] (char a, char b) {
      if (tolower(a) == tolower(b)) {
        return a < b;
      } else {
        return tolower(a) < tolower(b);
      }

    });
    cout << temp << endl;
  }
}
