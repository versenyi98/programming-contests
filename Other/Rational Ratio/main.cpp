#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

ll egesz, tort, vegtelen;
ll l_egesz, l_tort, l_vegtelen;

string line;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(max(a, b) % min(a, b), min(a, b));
}

ll pow (ll n, ll k) {
    ll ret = 1;
    for (ll l = 0; l < k; l++) {
        ret *= n;
    }

    return ret;
}

int main() {
    while (cin >> line >> l_vegtelen) {

        egesz = l_egesz = 0;
        tort = l_tort = 0;
        vegtelen = 0;

        l_egesz = line.find('.');
        egesz = stoi(line.substr(0, l_egesz));

        l_tort = line.length() - l_egesz - l_vegtelen - 1;
        if (l_tort) tort = stoi(line.substr(l_egesz + 1, l_tort));

        vegtelen = stoi(line.substr(line.length() - l_vegtelen, l_vegtelen));
        
        //cout << egesz << " " << tort << " " << vegtelen << endl;

        ll p = egesz * pow(10, l_vegtelen + l_tort) + tort * pow(10, l_vegtelen) + vegtelen;
        ll q = pow(10, l_vegtelen + l_tort) - pow(10, l_tort);
        p = p - (egesz * pow(10, l_tort) + tort);
        
        ll gcd_pq = gcd(p, q);
        p = p/gcd_pq;
        q = q/gcd_pq;

        cout << p << "/" << q << endl;
    }
    return 0;
} 