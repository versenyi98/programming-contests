#include <bits/stdc++.h>

using namespace std;

int main() {

    string line1;
    string line2;

    cin >> line1 >> line2;

    while (line1.back() == line2.back() && line1.back() == '0') {
        line1.pop_back();
        line2.pop_back();
    }

    if (line2.length() == 1) {
        cout << line1 << endl;
    } else if (line1.length() >= line2.length()) {
        cout << line1.substr(0, line1.length() - line2.length() + 1) << "." << line1.substr(line1.length() - line2.length() + 1) << endl;
    } else {
        cout << "0.";
        for (int i = line1.length(); i < line2.length() - 1; i++) cout << "0";
        cout << line1 << endl;
    }

    return 0;
}