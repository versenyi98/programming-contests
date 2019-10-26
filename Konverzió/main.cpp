#include <iostream>
#include <ctype.h>

using namespace std;

string line;
int index;
string result;

// Zárójel akkor kell ha osztás/szorzás után van összeadás/kivonás
// illetve ha osztás jobb oldalán szorzás van (azt hiszem)

void inorder(bool m_or_s = false, bool s = false) {

    if (index < 0) return;

    if (isalpha(line[index])) {
        result = line[index] + result;
    } else {
        int index_backup = index;
        bool current_s = line[index_backup] == '/';
        bool current_m = line[index_backup] == '*';

        index--;
        if ((s && current_m) || (!(current_s || current_m) && m_or_s)) result = ')' + result;
        inorder((current_s || current_m), current_s);
        
        result = line[index_backup] + result;
        
        index--;
        inorder(current_s || current_m);
        if ((s && current_m) || (!(current_s || current_m) && m_or_s)) result = '(' + result;
    }
}

int main() {

    cin >> line;
    index = line.length() - 1;
    inorder();
    cout << result << endl;
}