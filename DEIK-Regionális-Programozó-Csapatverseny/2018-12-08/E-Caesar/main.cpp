#include <iostream>
#include <vector>

using namespace std;

bool shouldDraw(vector<int> v, int X) {

  int sum = 0, sumLess = 0;

  for (int i = 0; i < v.size(); i++) {
    if (i + 2 <= X) {
      sumLess += v[i];
    }
    sum += v[i];
  }

  return (sumLess > sum-sumLess);
}

int main() {

  int N;
  cin >> N;

  vector<int> v;

  for (int i = 0; i <= 7; i++) {
    v.push_back(4);
  }

  v.push_back(16);
  v.push_back(4);


  int temp, sum = 0;;


  while (N--) {
    cin >> temp;
    v[temp - 2]--;
    sum += temp;
  }

  if(shouldDraw(v, 21-sum)) {
    cout << "DRAW" << endl;
  } else {
    cout << "STOP" << endl;
  }
}
