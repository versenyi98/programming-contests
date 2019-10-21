#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

int main () {

  int test;
  cin >> test;

  for (int i = 0; i < test; i++) {
    int coords;
    cin >> coords;

    long long minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;

    for (int j = 0; j < coords; j++) {
      long long  x;
      cin >> x;
      minx = min(minx, x);
      maxx = max(maxx, x);

      long long y;
      cin >> y;
      miny = min(miny, y);
      maxy = max(maxy, y);
    }

    long long a = max(abs(maxx - minx), abs(maxy - miny));
    cout << a*a << endl;
  }
}
