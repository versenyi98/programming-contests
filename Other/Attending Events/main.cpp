#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(true);

    int n;
    int c = 1;
    cin >> n;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == c) {
            c++;
            c = c % 4;
            if (c == 0) c++;
            r++;
       }
        
    }
    cout << r << endl;
    return 0;

}