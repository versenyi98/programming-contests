#include <iostream>

using namespace std;

int lines, trash;
string preorder, inorder;

void write_post(string pre, string in) {

    if (pre.length() == 0) return;

    int pos = in.find(pre[0]);

    write_post(pre.substr(1, pos), in.substr(0, pos));
    write_post(pre.substr(pos + 1), in.substr(pos + 1));

    cout << pre[0];
}

int main () {
    cin >> lines;

    while (lines--) {
        cin >> trash >> preorder >> inorder;
        write_post(preorder, inorder);
        cout << endl;
    }
}