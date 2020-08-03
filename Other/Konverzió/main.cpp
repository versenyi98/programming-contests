#include <iostream>
#include <ctype.h>

using namespace std;

string line;
int index;
string result;

void inorder(bool m_or_s = false, bool d = false, bool s = false) {

    if (index < 0) return;

    if (isalpha(line[index])) {
        result = line[index] + result;
    } else {
        int index_backup = index;
        bool current_d = line[index_backup] == '/';
        bool current_m = line[index_backup] == '*';
        bool current_s = line[index_backup] == '-';
        bool current_a = line[index_backup] == '+';

        index--;
        if ((s && (current_a || current_s)) || (d && (current_m || current_d)) || (!(current_d || current_m) && m_or_s)) result = ')' + result;
        inorder((current_d || current_m), current_d, current_s);
        
        result = line[index_backup] + result;
        
        index--;
        inorder(current_d || current_m);
        if ((s && (current_a || current_s)) || (d && (current_m || current_d)) || (!(current_d || current_m) && m_or_s)) result = '(' + result;
    }
}

int main() {

    cin >> line;
    index = line.length() - 1;
    inorder();
    cout << result << endl;
}