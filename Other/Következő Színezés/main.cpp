#include <iostream>
#include <stdio.h>

using namespace std;

// F -> P
// P -> F Z P
// Z -> Z F

int n;
string line;

bool valid(string str) {
  for (int i = 0; i < str.length() - 1; i++) {
    if (!(
      (str[i] != 'F' || str[i + 1] == 'P') &&
      (str[i] != 'P' || str[i + 1] == 'F' || str[i + 1] == 'Z' || str[i + 1] == 'P') &&
      (str[i] != 'Z' || str[i + 1] == 'Z' || str[i + 1] == 'F')
    )) {
      return false;
    }

  }

  return true;
}

string fill_rest(string str, int len) {

  for (int i = 0; i < len; i++)  {
    if (valid(str + 'F')) {
      str += 'F';
    } else if (valid(str + 'P')) {
      str += 'P';
    } else if (valid(str + 'Z')) {
      str += 'Z';
    }
  }

  return str;
}

string next_line() {

  for (int i = n - 1; i >= 0; i--) {

    string truncated = line.substr(0, i);

    if (line[i] < 'F' && valid(truncated + 'F')) {
      truncated += 'F';
      return fill_rest(truncated, n - 1 - i);
    } else if (line[i] < 'P' && valid(truncated + 'P')) {
      truncated += 'P';
      return fill_rest(truncated, n - 1 - i);
    } else if (line[i] < 'Z' && valid(truncated + 'Z')) {
      truncated += 'Z';
      return fill_rest(truncated, n - 1 - i);
    }
  }

  return fill_rest("", n);
}

int main() {

  cin >> n >> line;
  cout << next_line() << endl;

  return 0;
}
