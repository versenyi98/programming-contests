#include <iostream>

using namespace std;

int main() {

  int number;
  int counter = 0;

  cin >> number;

  for (int i = 1; i <= number; i++) {
    int j = i;
    while (j % 5 == 0) {
      counter++;
      j = j/5;
    }
  }

  cout << counter << endl;
}
