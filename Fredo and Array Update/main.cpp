#include <iostream>

using namespace std;

int main() {

  int num;
  cin >> num;

  int temp;
  long long initialS = 0;

  for (int i = 0; i < num; i++) {
    cin >> temp;
    initialS+=temp;
  }

  cout << initialS/num + 1 << endl;

}
