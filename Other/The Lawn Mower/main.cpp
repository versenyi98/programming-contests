#include <iostream>
#include <math.h>

using namespace std;

int main() {

  int rows;
  cin >> rows;

  for (int i = 0; i < rows; i++) {

    long long a, b;
    cin >> a;
    cin >> b;

    long long shorter = min(a, b);

    cout << shorter*2-2 << endl;
  }
}
