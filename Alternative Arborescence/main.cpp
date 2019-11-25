#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

#define COLORS 15

using namespace std;

map<int, vector<int> > childs;
bool touched[10000];
int sum_of_colors[10000][COLORS];
int nodes;
char ch;

bool is_everything_touched() {
    for (int i = 0; i < nodes; i++) {
        if (!touched[i]) return false;
    }

    return true;
}

int main() {

    while(cin >> nodes, nodes != 0) {

        childs.clear();

        for (int i = 0; i < nodes; i++) {

            for (int j = 0; j < COLORS; j++) {
                sum_of_colors[i][j] = j + 1;
            }
            touched[i] = false;

            int node;
            cin >> node;

            scanf("%c", &ch);
            while(scanf("%c", &ch), ch != '\n') {
                int temp;
                cin >> temp;

                childs[node].push_back(temp);
            }
        }

        for (int i = 0; i < nodes; i++) {
            if (childs[i].size() == 0) {
                touched[i] = true;
            }
        }

        int root = 0;
        while (!is_everything_touched()) {
            
            for (int i = 0; i < nodes; i++) {

                bool con = false;

                if (!touched[i]) {
                    for (int j = 0; j < childs[i].size(); j++) {
                        if (!touched[childs[i][j]]) {
                            con = true;
                            break;
                        }
                    }
                    if (con) continue;
                    root = i;
                    touched[i] = true;

                    break;
                }
            }

            for (int i = 0; i < COLORS; i++) {
                int result = i + 1;

                for (int j = 0; j < childs[root].size(); j++) {
                    int minimum = 10000;
                    for (int k = 0; k < COLORS; k++) {
                        if (k == i) continue;
                        minimum = min(sum_of_colors[childs[root][j]][k], minimum);
                    }
                    result += minimum;
                }

                sum_of_colors[root][i] = result;
            }
        }
        
        int minimum = 9999999;

        for (int i = 0; i < COLORS; i++) {
            minimum = min(minimum, sum_of_colors[root][i]);
        }

        /*
        for (int j = 0; j < nodes; j++) {
            cout << j << ": ";
            for (int i = 0; i < COLORS; i++) {
                cout << sum_of_colors[j][i] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        */

       cout << minimum << endl;
    }
}