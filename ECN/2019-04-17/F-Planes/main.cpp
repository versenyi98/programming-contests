#include <iostream>
#include <set>

using namespace std;

int main() {

  pair<int, int> moves[4];

  moves[0] = make_pair(+1, 0);
  moves[1] = make_pair(-1, 0);
  moves[2] = make_pair(0, +1);
  moves[3] = make_pair(0, -1);

  int rows;

  cin >> rows;

  for (int i = 0; i < rows; i++) {
    set<pair<int, int >> usedPos;
    pair<int, int> current = make_pair(0, 0);

    usedPos.insert(current);

    string line;
    cin >> line;

    for (int i = 0; i < line.length(); i++) {

      if (line[i] == 'N') {
        current = make_pair(current.first + moves[0].first, current.second + moves[0].second);
      } else if (line[i] == 'S') {
        current = make_pair(current.first + moves[1].first, current.second + moves[1].second);
      } else if (line[i] == 'E') {
        current = make_pair(current.first + moves[2].first, current.second + moves[2].second);
      } else if (line[i] == 'W') {
        current = make_pair(current.first + moves[3].first, current.second + moves[3].second);
      }
      usedPos.insert(current);
    }
    cout << usedPos.size() << endl;
  }
}
