#include <iostream>
#include <cmath>

using namespace std;

int main() {

  long long n;
  cin >> n;

  for (long long i = 0; i < n; i++) {

    int num;
    cin >> num;

    long long result = 0;
    long long current = 5;

    while (current <= num) {
      result += num/current;
      current *= 5;
    }
    cout << result << endl;
  }
}
