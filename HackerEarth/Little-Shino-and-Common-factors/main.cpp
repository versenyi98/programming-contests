#include <iostream>
#include <math.h>

using namespace std;

long long gcd (long long a, long long b) {

  if (a == 0) return b;
  if (b == 0) return a;

  return gcd (min(a, b), max(a, b) % min(a, b));
}

long long numberOfFactors(long long a) {
  long long val = 0;
  for (long long i = 1; i*i <= a; i++) {
    if (a % i == 0) {
      val += (i * i == a) ? 1 : 2;

    }
  }

  return val;
}


int main() {

  long long a, b;

  cin >> a;
  cin >> b;

  cout << numberOfFactors(gcd(max(a, b), min(a, b))) << endl;

}
