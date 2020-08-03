#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> worse;

bool isWorse(string a, string b) {

  if (a == b) return true;

  for (auto i: worse[a]) {
    if (isWorse(i, b)) return true;
  }

  return false;
}

int main() {

  int n, m;
  string a, b, temp;

  cin >> n >> m;

  while(n--) {
    cin >> a >> temp >> temp >> temp >> b;
    worse[a].push_back(b);
  }

  while(m--) {
    cin >> a >> temp >> temp >> temp >> b;

    if (isWorse(a, b)) {
      cout << "Fact\n";
    } else if (isWorse(b, a)) {
      cout << "Alternative Fact\n";
    } else {
      cout << "Pants on Fire\n";
    }
  }
}
