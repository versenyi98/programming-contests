#include <bits/stdc++.h>

using namespace std;

int main() {

    long x, xx, y, yy, p, pp, q, qq;

    cin >> x >> y >> p >> q;

    xx = x;
    yy = y;
    pp = p;
    qq = q;

    while (true) {

        while (xx < pp) xx += x;
        while (yy < qq) yy += y;
        while (pp < xx || qq < yy) {
            pp += p;
            qq += q;
        }

        if (xx == pp && yy == qq) break;
    }

    cout << xx / x << ' ' << yy / y << ' ' << pp / p << endl;
}