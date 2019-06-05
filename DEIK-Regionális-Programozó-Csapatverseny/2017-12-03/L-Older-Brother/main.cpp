#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main() {

  long long border;
  long long current = 2;

  set<long long> divisors;

  cin >> border;

  while (border != 1) {

    if (divisors.size() > 1) {
      break;
    }

    if (border % current == 0) {
      border = border / current;
      divisors.insert(current);
      continue;
    }

    if (divisors.size() == 0 && current >= sqrt(border)) {
      divisors.insert(border);
      break;
    }

    current++;
  }

  if (divisors.size() == 1) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

}
