#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define pii pair<int, int>

int n, m;
map<int, string> trains;
map<pii, pii> traffic;
vector<pair<pii, pii>> traffic2;

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        string temp1;

        cin >> temp >> std::ws;
        getline(cin, temp1);
        trains[temp] = temp1;
//        cout << temp << " " << temp1 << endl;
    }

    for (int i = 0; i < m; i++) {
        int trash;
        char trash1;

        int rest, dep, arr;
        cin >> trash >> rest >> dep >> trash >> trash1 >> trash >> arr >> trash >> trash1 >> trash;
//        cout << rest << " " << dep << " " << arr << endl;
    
        int mi = dep, mx = arr;
        int value = 1;

        if (trains[dep] > trains[arr]) {
            mx = dep;
            mi = arr;
            value = -1;
        }

        if (rest) {
            traffic[{mi, mx}].f += value;
        } 
        traffic[{mi, mx}].s += value;
    }
    for (auto i : traffic) {
        traffic2.push_back({i.f, i.s});
    }

    sort(traffic2.begin(), traffic2.end(), [] (pair<pii, pii> a, pair<pii, pii> b) {
        if (trains[a.f.f] == trains[b.f.f]) {
            return trains[a.f.s] < trains[b.f.s];
        }
        return trains[a.f.f] < trains[b.f.f];
    });

    for (auto i : traffic2) {
        if (i.s.s) {
            cout << i.f.f << " " << trains[i.f.f] << " - " << i.f.s << " " << trains[i.f.s] << ", number of trains\n";
            continue;
        }

        if (i.s.f) {
            cout << i.f.f << " " << trains[i.f.f] << " - " << i.f.s << " " << trains[i.f.s] << ", restrictions\n";
            continue;
        }      
    }
}
