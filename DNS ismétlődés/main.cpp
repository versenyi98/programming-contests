#include <bits/stdc++.h>

using namespace std;

int current_max = 0;
int current_max_pos = 0;

string current_DNS = "";

int N, K;

map<string, bool> already_taken;
map<string, int> occurances;
map<string, int> first_pos;


int main() {

    cin >> N >> K;

    char ch;
    for (int i = 1; i <= N; i++) {
        cin >> ch;

        current_DNS += ch;

        if (i >= K) {
            string sub = current_DNS.substr(i - K, K);

            if (!already_taken[sub]) {
                already_taken[sub] = true;
                first_pos[sub] = i - K + 1;
            }

            occurances[sub]++;

            if (occurances[sub] > current_max) {
                current_max = occurances[sub];
                current_max_pos = first_pos[sub];
            }
        }
    }

    cout << current_max << " " << current_max_pos << endl;
}