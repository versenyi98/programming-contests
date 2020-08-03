#include <iostream>

using namespace std;

int tasks, minutes;

int main() {

    cin >> tasks >> minutes;
    int task;

    for (int i = 0; i < tasks; i++) {
        cin >> task;
        minutes -= task;    
    

        if (minutes < 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << tasks << endl;
}