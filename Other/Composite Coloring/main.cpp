#include <bits/stdc++.h>

using namespace std;

int divisiors[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int main() {

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        map<int, bool> has_val;
        map<int, int> value;
        queue<int> sol;

        int current_color_size = 0;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            for (int k = 0; k < 11; k++) {

                if (t % divisiors[k] == 0) {
                    if (has_val[k]) {
                        sol.push(value[k]);
                    } else {
                        value[k] = ++current_color_size;
                        has_val[k] = true;
                        sol.push(value[k]);
                    }

                    break;
                }
            }
        }
        
        cout << current_color_size << endl;
        bool entry = false;
        while (sol.size()) {
            if (entry) cout << ' ';
            entry = true;
            cout << sol.front();
            sol.pop();
        }
        cout << endl;
    }
}