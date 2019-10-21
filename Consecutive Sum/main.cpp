#include <iostream>

using namespace std;

int main() {

  int num;

  while (cin >> num) {
    if (num == 0) break;

    int start = 1, end = 1, sum = 1;

    while (start <= num/2) {

      while (sum < num) {
        end++;
        sum+=end;
      }

      while (sum > num) {
        sum-=start;
        start++;
      }

      if (sum == num) {
        cout << start << ' ' << end << endl;
        sum-=start;
        start++;
      }
    }
    cout << endl;
  }
}
