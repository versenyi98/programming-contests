#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int number;
  vector<int> days;

  cin >> number;

  int temp;

  for (int i = 0; i < number; i++) {
    cin >> temp;
    days.push_back(temp);
  }

  sort(days.begin(), days.end(), greater<int>());

  for (int i = 0; i < days.size(); i++) {
    days[i] += i + 1;
  }

  sort(days.begin(), days.end(), greater<int>());


  cout << days[0] + 1 << endl;
}
