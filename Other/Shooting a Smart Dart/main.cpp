#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
#define f first
#define s second
int test_cases;

int main() {

    cin >> test_cases;
    int n;
    while (test_cases--) {
        cin >> n;
        vector<pair<long long, long long>> p;
        unsigned long long minimal = -1;

        for (int i = 0; i < n; i++) {
            long long x, y;
            cin >> x >> y;

            for (int j = 0; j < i; j++) {
                minimal = min(minimal, (unsigned long long)((p[j].f - x) * (p[j].f - x) + (p[j].s - y) * (p[j].s - y)));
            }

            p.push_back({x, y});
        }

        unsigned long long l, r, m;
        minimal = minimal * 100 * 100;
        l = minimal;
        r = 1;
        m = (l + r) / 2;

        while (l - r != 1) {

            if (minimal / m < m) {
                l = m;
                m = (l + r) / 2;
            }
            else {
                r = m;
                m = (l + r) / 2;
            }
            //cout << "l " << l << " r " << r << " m " << m << endl;
        }
        printf("%.2f\n", m / 100.00);
    }
}