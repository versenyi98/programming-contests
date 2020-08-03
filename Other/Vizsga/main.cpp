#include <bits/stdc++.h>

using namespace std;

int len;
int points;

string friend_, own_;

int main() {

    cin >> len >> points;
    cin >> friend_ >> own_;

    int positive_rem_point = points;
    int positive_rem_error = len - points;
    int positive_curr_points = 0;

    int negative_rem_point = points;
    int negative_rem_error = len - points;
    int negative_curr_points = 0;

    for (int i = 0; i < len; i++) {

        if (friend_[i] == own_[i] && positive_rem_point > 0) {
            positive_rem_point--;
            positive_curr_points++;
        } else if (friend_[i] != own_[i] && positive_rem_error > 0) {
            positive_rem_error--;
            positive_curr_points++;
        }

        if (friend_[i] == own_[i] && negative_rem_error > 0) {
            negative_rem_error--;
        } else if (friend_[i] != own_[i] && negative_rem_point > 0) {
            negative_rem_point--;
        } else {
            negative_curr_points++;
        }

    }

    cout << negative_curr_points << " " << positive_curr_points << endl;
}