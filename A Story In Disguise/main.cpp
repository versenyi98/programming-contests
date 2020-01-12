
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {

    int a, b;

    cin >> a >> b;
    int ret = 0;

    for (int i = 2; i <= a; i++) {
      ret = (ret + b) % i;
    }
    cout << ret + 1 << endl;
  }

  return 0;
}
