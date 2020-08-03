#include <bits/stdc++.h>

using namespace std;

struct point {
    int f;
    int s;
    int t;
};

int main() {

    int n;
    int dist[2001][2001];


    while (cin >> n, n > 0) {
        queue<point> q;

        int x, y;

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point p;
            p.f = x;
            p.s = y;
            p.t = 0;
            q.push(p);
        }

        for (int i = 0; i < 2001; i++)
            for (int j = 0; j < 2001; j++) 
                dist[i][j] = -1;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            dist[x][y] = 1;
        }

        while (true) {
            auto top = q.front();
            q.pop();

            if (top.f < 0 || top.f > 2000 || top.s < 0 || top.s > 2000 || dist[top.f][top.s] == 0) continue;

            if (dist[top.f][top.s] == 1) {
                cout << top.t << endl;
                break;
            }

            dist[top.f][top.s] = 0;

            top.t++;

            top.f--;
            q.push(top);

            top.f+=2;
            q.push(top);

            top.f--;
            top.s--;
            q.push(top);

            top.s+=2;
            q.push(top);
        }
    }
}