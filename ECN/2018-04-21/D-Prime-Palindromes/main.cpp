#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int number) {

  int divisors = 0;

  for (int i = 2; i <= sqrt(number); i++) {
    if (number%i == 0) {
      divisors++;
      break;
    }
  }
  return divisors == 0;
}

bool isPalindrome(string number) {

  if (number.length() <= 1) {
    return true;
  }

  return number[0] == number[number.length() - 1] && isPalindrome(number.substr(1, number.length()-2));
}

int main() {
  int start, end;
  while (cin >> start) {
    cin >> end;
    int counter = 0;
    for (int i = start; i < end; i++) {
      if (isPrime(i) && isPalindrome(to_string(i))) {
        counter++;
      }
    }
    cout << counter << endl;
  }
}
