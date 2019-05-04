#include <iostream>
#include <vector>

using namespace std;

bool is6 (vector<string> v) {

  if (!v[0].compare("ooo") && !v[1].compare(":::") && !v[2].compare("ooo")) return true;
  if (!v[0].compare("o:o") && !v[1].compare("o:o") && !v[2].compare("o:o")) return true;

  return false;
}

bool is5 (vector<string> v) {

  if (!v[0].compare("o:o") && !v[1].compare(":o:") && !v[2].compare("o:o")) return true;

  return false;
}

bool is4 (vector<string> v) {

  if (!v[0].compare("o:o") && !v[1].compare(":::") && !v[2].compare("o:o")) return true;

  return false;
}

bool is3 (vector<string> v) {

  if (!v[0].compare("::o") && !v[1].compare(":o:") && !v[2].compare("o::")) return true;
  if (!v[0].compare("o::") && !v[1].compare(":o:") && !v[2].compare("::o")) return true;

  return false;
}

bool is2 (vector<string> v) {

  if (!v[0].compare("::o") && !v[1].compare(":::") && !v[2].compare("o::")) return true;
  if (!v[0].compare("o::") && !v[1].compare(":::") && !v[2].compare("::o")) return true;

  return false;
}

bool is1 (vector<string> v) {

  if (!v[0].compare(":::") && !v[1].compare(":o:") && !v[2].compare(":::")) return true;

  return false;
}

int main() {
  vector<string> v;
  string tmp;

  for (int i = 0; i < 3; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }

  if (is1(v)) {
    cout << "1\n";
    return 0;
  }

  if (is5(v)) {
    cout << "5\n";
    return 0;
  }

  if (is4(v)) {
    cout << "4\n";
    return 0;
  }
  if (is3(v)) {
    cout << "3\n";
    return 0;
  }
  if (is2(v)) {
    cout << "2\n";
    return 0;
  }

  if (is6(v)) {
    cout << "6\n";
    return 0;
  }
  cout << "unknown\n";
}
