#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

int circle, lines;
string line;

vector<int> situation;

int main() {

    while(cin >> circle >> lines) {

        string str;
        for (int i = 0; i < lines; i++) {
            cin >> str;
            if (str == "undo") {
                int undo;
                cin >> undo;

                for (int j = 0; j < undo; j++) {
                    situation.pop_back();
                }
            } else {
                int num = stoi(str);
                if (!i) {
                    while (num < 0) {
                        num = circle + num;
                    }
                    situation.push_back(num % circle);
                } else {
                    int num2 = situation.back() + num;
                    while (num2 < 0) {
                        num2 = circle + num2;
                    }
                    situation.push_back(num2 % circle);
                }
            }
        }
        cout << situation.back() << endl;
        situation.clear();
    }
}