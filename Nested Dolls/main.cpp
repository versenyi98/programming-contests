#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> DOLL(20000);
int DOLL_SIZE;

pair<int, int> LIS[20000];
int LIS_SIZE;

int lis[20000];
int result;
void LIS_F(int i) {

    int j = 0;
    while (DOLL[i].second >= LIS[j].second && j < LIS_SIZE) j++;
    if (j == LIS_SIZE) {
        LIS[j] = DOLL[i];
        LIS_SIZE++;
    } else if (DOLL[i].second <= LIS[j].second) {
        LIS[j] = DOLL[i];
    }
    
    result = max(j, result);
}

int main() {

    int tc;
    cin >> tc;
    for (int ttt = 0; ttt < tc; ttt++) {
        cin >> DOLL_SIZE;
        result = 0;
        LIS_SIZE = 0;

        for (int i = 0; i < DOLL_SIZE; i++) {
            cin >> DOLL[i].first >> DOLL[i].second;
            lis[i] = 0;
        }

        sort(DOLL.begin(), DOLL.begin() + DOLL_SIZE, [] (pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        for (int i = 0; i < DOLL_SIZE; i++) LIS_F(i);

        if (DOLL_SIZE == 0) {
            cout << 0 << endl;
            continue;
        }
        cout << result + 1  << endl;
    }
}