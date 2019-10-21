#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {

  int rows;
  cin >> rows;

  vector<pair<string, double>> v;

  for (int i = 0; i < rows; i++) {
    string sTemp;
    cin >> sTemp;

    double dTemp;
    cin >> dTemp;
    v.push_back(make_pair(sTemp, dTemp));
  }

  double amount;
  cin >> amount;

  for (int i = 0; i < rows; i++) {
    cout << v[i].first;
    printf(" %.2f\n", round(100*100/v[i].second*amount)/100);
  }
}
