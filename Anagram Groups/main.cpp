#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {

  set<string> s;
  map<string, vector<string>> m;
  string temp;

  while (cin >> temp) {

    if(s.insert(temp).second) {
      string temp2 = temp;
      sort(temp.begin(), temp.end());
      m[temp].push_back(temp2);
    }
  }

  vector<pair<string, vector<string>>> result;

  for (auto i : m) {
    result.push_back(make_pair(i.first, i.second));
    sort(result[result.size()-1].second.begin(), result[result.size()-1].second.end());
  }

  sort(result.begin(), result.end(), [](pair<string, vector<string>> a, pair<string, vector<string>> b) -> bool {
    if (a.second.size() != b.second.size()) {
      return a.second.size() > b.second.size();
    } else {
        return b.second[0] > a.second[0];
    }
  });
  
  result.erase(result.begin()+5, result.end());

  for (unsigned int i = 0; i < result.size(); i++) {
    cout << "Group of size " << result[i].second.size() << ":";
    for (unsigned int j = 0; j < result[i].second.size(); j++) {
      cout << " " << result[i].second[j];
    }
    cout << endl;
  }
}
