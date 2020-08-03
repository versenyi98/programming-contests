#include <bits/stdc++.h>

using namespace std;

int main() {

    string str;
    cin >> str;

    uint64_t K;
    cin >> K;

    uint64_t c[26];

    for (uint64_t i = 0; i < 26; i++) c[i] = 0;
    for (auto i : str) {
        c[i - 'a']++;
    }

    for (uint64_t i = 0; i < K; i++) {
        for (uint64_t j = 0; j < 26; j++) c[j]*=2;
        if (i) c[str[0] - 'a']--;
        if (i == 0) c[str.back() - 'a']--;
    }  
    
    for (uint64_t i = 0; i < 26; i++) {
        if (i) cout << ' ';
        cout << c[i];
    }
    cout << endl;


    return 0;
}
