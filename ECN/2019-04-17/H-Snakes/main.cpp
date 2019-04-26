#include <iostream>

using namespace std;

int main() {

  int num;

  while (cin >> num) {
    if (num == 0) break;

    cout << '/';
    for (int i = 0; i < num; i++) {
      cout << '-';
    }
    cout << "   ";
    for (int i = 0; i < num; i++) {
      cout << '-';
    }
    cout << '\\';
    cout << endl;

    for (int i = 0; i < num; i++) {
      cout << '|';
      for (int j = 0; j < num*2+3; j++) {
        cout << ' ';
      }
      cout << '|' << endl;
    }
    cout << '\\';
    for (int i = 0; i < num; i++) {
      cout << '-';
    }
    cout << "\\ /";
    for (int i = 0; i < num; i++) {
      cout << '-';
    }
    cout << '/';
    cout << endl;
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < num+1; j++) {
        cout << ' ';
      }
      cout << "| |" << endl;
    }

    cout << ' ';
    for (int i = 0; i < num; i++) {
      cout << '-';
    }
    cout << "/ \\";
    for (int i = 0; i < num; i++) {
      cout << '-';
    }

    cout << endl << endl;
  }
}
