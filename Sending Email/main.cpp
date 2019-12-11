#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000

int test_cases;
int nodes, edges, from, to;
int dist[20000];

int main () {

    scanf("%d", &test_cases);

    for (int tt = 0; tt < test_cases; tt++) {
        scanf("%d %d %d %d", &nodes, &edges, &from, &to);
        for (int i = 0; i < nodes; i++) dist[i] = MINUS_INF;
        dist[from] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({0, from});

        map<int, vector<pair<int, int>>> con;
        
        int x, y, c;
        for (int i = 0; i < edges; i++) {
            scanf("%d %d %d", &x, &y, &c);
            con[x].push_back({y, c});
            con[y].push_back({x, c});
        }

        while (!pq.empty() && pq.top().s != to) {
            auto current = pq.top();
            pq.pop();

            for (auto i : con[current.s]) {
                if (dist[i.f] < dist[current.s] - i.s) {
                    dist[i.f] = dist[current.s] - i.s;
                    pq.push({dist[i.f], i.f});
                }
            }
        }
        printf("Case #%d: ", tt + 1);
        if (pq.empty()) {
            printf("unreachable\n");
        } else {
            printf("%d\n", -pq.top().f);
        }
    }
}