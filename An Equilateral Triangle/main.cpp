#include <iostream>

using namespace std;

long long countUntilN(long long n) {

  long long value = 0;

  for (long long i = 0; i <= n; i++) {
    value += i;
  }

  return value;
}

int main() {

  long long n;
  cin >> n;

  long long count = 0;
  long long step = 2;
  n = n - 2;

  for (int i = n; i > 0; i--) {
    count += step/2 * countUntilN(i);
    step++;
  }

  cout << count << endl;
}
