#include <iostream>
#include <set>

using namespace std;

int main() {

  int cases;

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    int N, X;

    cin >> N;
    cin >> X;

    set<int> s;

    int temp;
    for (int i = 0; i < N; i++) {
      cin >> temp;
      s.insert(temp);
    }

    if (s.size() == X) {
      cout << "Good" << endl;
    } else if (s.size() < X) {
      cout << "Bad" << endl;
    } else {
      cout << "Average" << endl;
    }


  }





}
