#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define pss pair<string, string>

map<int, pss> m;
vector<pair<int, pss>> v;
int n;

int main() {

    cin >> n;

    while (n--) {
        int id;
        string status, name;

        cin >> id >> status;
        getline(cin, name);

        m[id] = {status, name.substr(1, name.length() - 1)};
    }

    int female = 0, male = 0, cs = 0, secret = 0;
    for (auto i : m) {

        if (i.second.first.find('-') != string::npos) {
            continue;
        }

        if (i.second.first[0] == 'F') {
            female++;
        } else if (i.second.first[0] == 'M') {
            male++;
        }

        bool c = false, s = false;

        if (i.second.first.find('C') != string::npos) {
            cs++;
            c = true;
        }

        if (i.second.first.find('S') != string::npos) {
            secret++;
            s = true;
        }

        if (s && c) {
            v.push_back(i);
        }
    }

    sort(v.begin(), v.end(), [] (pair<int, pss> a, pair<int, pss> b) {
        return a.second.second < b.second.second;
    });

    cout << male << " men\n" << female << " women\n";
    cout << cs << " computer scientists\n" << secret << " for secret service\n\n";
    
    for (auto i : v) {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }

}