#include <bits/stdc++.h>

using namespace std;

int diff(string s1, string s2) {
    int diffs = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) diffs++;
    }
    return diffs;
}

int main() {

    int n;
    cin >> n;
    for (int tt = 0; tt < n; tt++) {
        if (tt) cout << endl;
        string str, from, to;
        map<string, vector<string>> connections;
        vector<string> words;
        while (cin >> str && str != "*") {
            for (int i = 0; i < words.size(); i++) {
                if (str.size() == words[i].size() && diff(str, words[i]) == 1) {
                    connections[str].push_back(words[i]);
                    connections[words[i]].push_back(str);
                }
            }
            words.push_back(str);
        }

        getline(cin, str);
        while (getline(cin, str) && str.length()) {
            from = str.substr(0, str.find(' '));
            to = str.substr(str.find(' ') + 1);

            map<string, bool> taken;
            queue<pair<string, int>> q;

            q.push({from, 0});
        
            while (!q.empty() && q.front().first != to) {
                auto current = q.front();
                q.pop();

                if (taken[current.first]) continue;
                taken[current.first] = true;

                for (auto i : connections[current.first]) {
                    if (!taken[i]) {
                        q.push({i, current.second + 1});
                    }
                }
            }
            cout << from << " " << to << " " << q.front().second << endl;       
        }
    }
}