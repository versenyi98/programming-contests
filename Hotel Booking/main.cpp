#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000
#define INF 1000000000

#define maxN 10011
#define maxH 105

int number_of_cities;
int number_of_hotels;
int number_of_routes;

int d[maxN][maxH];
bool flag[maxN][maxH], hotel[maxN];
vector<pair<int, int>>adj[maxN];

int dijkstra() {
    d[1][0] = 0;
    set<pair<pair<int, int>, int>> heap;
    heap.insert({{0,0},1});

    while (heap.size()) {
        auto top = *heap.begin();
        heap.erase(top);

        int d1 = top.f.f;
        int d2 = top.f.s;
        int u = top.s;  

        if (u == number_of_cities ) return d1;

        flag[u][d1] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].f;
            int w = adj[u][i].s;

            if (d2 + w > 600) continue;
            int x = d1;
            int y = d2 + w;
            if (x > number_of_hotels + 1) continue;

            if (!flag[v][x] && y < d[v][x]) {
                if (d[v][x] != INF) heap.erase({{x, d[v][x]}, v});
                d[v][x] = y;
                heap.insert({{x, d[v][x]}, v});
            }
            if (hotel[v]) {
                x++, y = 0;
                if (!flag[v][x] && y < d[v][x]) {
                    if (d[v][x] != INF) heap.erase({{x, d[v][x]}, v});
                    d[v][x] = y;
                    heap.insert({{x, y}, v});
                }
            }
        }
    }
    return -1;
}

int main() {

    int x, y, c;
    int test = 0;
    
    while (cin >> number_of_cities, number_of_cities) {
        cin >> number_of_hotels;

        for (int i = 1; i <= number_of_cities; i++) {
            adj[i].clear();
            hotel[i] = false;

            for (int j = 0; j < number_of_hotels + 3; j++) {
                d[i][j] = INF;              // j. hotelhez táv i.től
                flag[i][j] = false;         // pos time
            } 
        }

        int temp;
        for (int i = 0; i < number_of_hotels; i++) {
            cin >> temp;
            hotel[temp] = true;             // has hotel
        }
        hotel[1] = false;
        hotel[number_of_cities] = false;
        cin >> number_of_routes;
        
        int u, v, w;
		while (number_of_routes--) {
			cin >> u >> v >> w;
			adj[u].push_back({v, w});       // connections
			adj[v].push_back({u, w});
		}
        printf("%d\n", dijkstra());
    }
}