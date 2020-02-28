#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> pre;
map<char, bool> taken;
int N;
string old_str, new_str;

void process(char c) {

    for (auto cc : pre[c]) {
        process(cc);
    }

    if (!taken[c]) {
        taken[c] = true;
        cout << c;
    }
}

int main() {

    cin >> N;
    cin >> old_str;

    for (int i = 0; i < N - 1; i++) {
        cin >> new_str;

        for (int j = 0; j < min(old_str.length(), new_str.length()); j++) {
            if (old_str[j] != new_str[j]) {
                pre[new_str[j]].push_back(old_str[j]);
                break;
            }
        }
        old_str = new_str;  
    }

    // A mintában szereplő megoldás eléréséhez csak (felesleges)
    for (auto i : pre) {
        process(i.first);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        process(c);
    }
    cout << endl;
}