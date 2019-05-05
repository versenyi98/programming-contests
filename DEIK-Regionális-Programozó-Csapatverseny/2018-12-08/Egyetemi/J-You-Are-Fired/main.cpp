#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  long long rows, dollars, k;

  cin >> rows;
  cin >> dollars;
  cin >> k;

  vector<pair<string, long long>> v;

  string strTemp;
  long long longTemp;

  for (long long i = 0; i < rows; i++) {
    cin >> strTemp;
    cin >> longTemp;

    v.push_back(make_pair(strTemp, longTemp));
  }

  sort(v.begin(), v.end(), [] (pair<string, long long> a, pair<string, long long> b) {
    return a.second > b.second;
  });

/*
  for (auto i : v) {
    cout << i.first << " " << i.second << endl;
  }
*/

  long long savedDollars = 0;
  long long fired = 0;
  while (savedDollars < dollars && fired < k) {

    savedDollars += v[fired].second;
    fired++;

  }

  if (savedDollars >= dollars) {
    cout << fired << endl;
    for (long long i = 0; i < fired; i++) {
      cout << v[i].first << ", YOU ARE FIRED!" << endl;
    }
    return 0;
  }

  cout << "impossible" << endl;
}
