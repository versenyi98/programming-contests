#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int a, b, c, a1, b1, c1;
    int sum = 0;
    cin >> a >> b >> c >> a1 >> b1 >> c1;

    sum += max(0, a1 - a) + max(0, b1 - b) + max(0, c1 - c);
    cout << sum << endl;
}