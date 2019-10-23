#include <iostream>
#include <map>

using namespace std;

map <char, int> szabad;

int n;
string szo;
string betuk;

string kovetkezo() {
    map <char, int> szabad_cp = szabad;

// Nem teljes szó következője 
    if (szo.length() != n) {
        for (auto i : szabad_cp) {
            if (i.second) {
                return szo + i.first;
            }
        }
    }

// Teljes szó következője
    for (int i = n - 1; i >= 1; i--) {
        if (szo[i] <= szo[i - 1]) {
            szabad_cp[szo[i]]++;
        } else {
            szabad_cp[szo[i]]++;
            for (auto j : szabad_cp) {
                if (j.second && j.first > szo[i - 1]) {
                    return szo.substr(0, i - 1) + j.first;
                }
            }
        }
    }

// Utolsó szó következője az első szó
    for (auto i : szabad_cp) {
        if (i.second) {
            return string(1, i.first);
        }
    }
}

string elozo() {
    map <char, int> szabad_cp = szabad;

// Teljes szó előzője
    if (szo.length() == n) {
        return szo.substr(0, szo.length() - 1);
    }

// Nem teljes szó előzője

    char levagott = szo[szo.length() - 1];
    string ret_str  = szo.substr(0, szo.length() - 1);
    szabad_cp[levagott]++;


    char maximum = (char) 0;

    for (auto i : szabad_cp) {
        if (i.second && i.first > maximum && i.first < levagott) {
            maximum = i.first;
        }
    }

    if (maximum == (char) 0 && ret_str.length() != 0) {
        return ret_str;
    } else if (maximum != (char) 0) {
        ret_str += maximum;
        szabad_cp[maximum]--;

        while (true) {
            char utolso = ' ';
            for (auto j : szabad_cp) {
                if (j.second) utolso = j.first;
            }
            
            if (utolso == ' ') {
                return ret_str;
            }
            ret_str += utolso;
            szabad_cp[utolso]--;
        }  
    }
    
// Első szó előzője az utolsó szó
    string ret = "";
    while (true) {
        char utolso = ' ';
        for (auto j : szabad_cp) {
            if (j.second) utolso = j.first;
        }
        if (utolso == ' ') return ret;
        ret += utolso;
        szabad_cp[utolso]--;
    }    
}

int main() {

    cin >> n >> betuk >> szo;

    for (int i = 0; i < n; i++) {
        szabad[betuk[i]]++;
    }

    for (int i = 0; i < szo.length(); i++) {
        szabad[szo[i]]--;
    }
    string elso = szo;

    do {
        cout << szo << endl;
        szo = elozo();

        for (int i = 0; i < n; i++) {
            szabad[betuk[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
            szabad[betuk[i]]++;
        }
        for (int i = 0; i < szo.length(); i++) {
            szabad[szo[i]]--;
        }

    } while (elso.compare(szo) != 0);

    cout << endl;

    do {
        cout << szo << endl;
        szo = kovetkezo();

        for (int i = 0; i < n; i++) {
            szabad[betuk[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
            szabad[betuk[i]]++;
        }
        for (int i = 0; i < szo.length(); i++) {
            szabad[szo[i]]--;
        }

    } while (elso.compare(szo) != 0);

}