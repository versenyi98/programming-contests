#include <iostream>

using namespace std;

int rotate(string str) {

  int r = 0;
  for (int i = 0; i < str.length(); i++) {
    r += (int)(str[i]-'A');
  }

  return r;
}

string rotate2(string str, int rotation) {
  
  for (int i = 0; i < str.length(); i++) {
    str[i] = 'A' + (((int)str[i]+rotation-'A')%26);
  }

  return str;
}

int main() {

  string msg, h1, h2;
  int r1 = 0, r2 = 0, r3 = 0;
  getline(cin, msg);

  h1 = msg.substr(0, msg.length()/2);
  h2 = msg.substr(msg.length()/2);

//  cout << h1 << endl;
//  cout << h2 << endl;

  r1 = rotate(h1);
  r2 = rotate(h2);

  h1 = rotate2(h1, r1);
  h2 = rotate2(h2, r2);

//  cout << h1 << endl;
//  cout << h2 << endl;

  for (int i = 0; i < h1.size(); i++) {
    h1[i] = 'A' + ((int)(h1[i] + h2[i] - 'A' - 'A')%26);
  }

  cout << h1 << endl;
}
