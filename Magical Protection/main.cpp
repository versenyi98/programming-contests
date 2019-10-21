#include <iostream>
#include <vector>

using namespace std;

void printV(vector<string> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  cout << endl;
}

void expandVoldemort(vector<string> &v, int x, int y, int h, int w) {
  if (y >= h || y < 0 || x >= w || x < 0 || v[y][x] == 'D' || v[y][x] == '1' || v[y][x] == '2') return;

  v[y][x] = '2';

  expandVoldemort(v, x-1, y+0, h, w);
  expandVoldemort(v, x+0, y-1, h, w);
  expandVoldemort(v, x+0, y+1, h, w);
  expandVoldemort(v, x+1, y+0, h, w);
}

void expandDumbledore(vector<string> &v, int x, int y, int h, int w) {
  if (y >= h || y < 0 || x >= w || x < 0) return;

  v[y][x] = '1';
}

void solve(vector<string> &v, int &hx, int &hy, int &dx, int &dy, int &vx, int &vy) {

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].length(); j++) {
      switch (v[i][j]) {
        case '0': break;
        case '1': break;
        case 'H': {
          hy = i;
          hx = j;
          break;
        }
        case 'V': {
          vy = i;
          vx = j;
          break;
        }
        case 'D': {
          dy = i;
          dx = j;
          break;
        }
      }
    }
  }

  //Dumbledore Walls;
  expandDumbledore(v, dx - 1, dy - 1, v.size(), v[vy].length());
  expandDumbledore(v, dx - 1, dy - 0, v.size(), v[vy].length());
  expandDumbledore(v, dx - 1, dy + 1, v.size(), v[vy].length());
  expandDumbledore(v, dx, dy, v.size(), v[vy].length());
  expandDumbledore(v, dx - 0, dy + 1, v.size(), v[vy].length());
  expandDumbledore(v, dx - 0, dy - 1, v.size(), v[vy].length());
  expandDumbledore(v, dx + 1, dy - 1, v.size(), v[vy].length());
  expandDumbledore(v, dx + 1, dy - 0, v.size(), v[vy].length());
  expandDumbledore(v, dx + 1, dy - 1, v.size(), v[vy].length());

  //printV(v);
  expandVoldemort(v, vx, vy, v.size(), v[vy].length());
  //printV(v);
}

int main() {

  string line;

  int counter = 0;
  vector<string> v;
  while (getline(cin, line)) {
    if (line.length() == 0) {
      counter++;
      if (counter == 2) {
        break;
      }

      int hx, hy;
      int dx, dy;
      int vx, vy;

      solve(v, hx, hy, dx, dy, vx, vy);

      if (v[hy][hx] == '2') {
        cout << "Voldemort can kill Harry." << endl;
      } else {
        cout << "Voldemort cannot kill Harry." << endl;
      }

      v.clear();
      continue;
    } else {
      v.push_back(line);
      counter = 0;
    }
  }
}
