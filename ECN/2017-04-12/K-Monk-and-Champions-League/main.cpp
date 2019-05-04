#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

  long long rows, people;
  long long sum = 0;

  priority_queue<long long, vector<long long>, less<long long>> pq;

  cin >> rows;
  cin >> people;

  long long temp;

  for (int i = 0; i < rows; i++) {
    cin >> temp;
    pq.push(temp);
  }

  for (long long i = 0; i < people; i++) {
    long long x = pq.top();
    sum += x;
    x--;
    pq.pop();
    pq.push(x);
  }

  cout << sum << endl;
}
