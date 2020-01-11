#include <bits/stdc++.h>

using namespace std;

string to_str(const vector<string>& v) {
    string st = "";

    for (int i = 0; i < v.size(); i++) {
        if (i) st+="+";
        st+=v[i];
    }
    return st;
}

int main () {

    string line;
    
    vector<string> reactions;

    map<string, bool> has_next;
    map<string, string> next;

    vector<string> original;

    getline(cin, line);

    size_t plus;
    while (plus = line.find('+'), plus != string::npos) {
        original.push_back(line.substr(0, plus));
        line = line.substr(plus + 1);
    }
    original.push_back(line);

    int num;
    cin >> num;

    string from, to;
    for (int i = 0; i < num; i++) {
        cin >> from >> to;
        has_next[from] = true;
        next[from] = to;
    }

    vector<string> actual = original;
    int index = actual.size() - 1;

    while (true) {
        if (index == 0 && has_next[actual[0]] == false) break;

        if (!has_next[actual[index]]) {
            for (int i = index; i < actual.size(); i++) {
                actual[i] = original[i];
            }
            index--;
            continue;
        }

        actual[index] = next[actual[index]];
        index = actual.size() - 1;

        reactions.push_back(to_str(actual));
    }

    sort(reactions.begin(), reactions.end());
    unique(reactions.begin(), reactions.end());

    cout << reactions.size() + 1 << endl;
    for (auto i : reactions) {
        cout << i << endl;
    }
    return 0;
}
