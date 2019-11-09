#include <iostream>
#include <vector> 

using namespace std;

#define coord pair<int, int>
#define x first
#define y second
#define node pair<coord, int>

int N, M;
int room[10][10];
int index = 0;

vector<node> nodes;

bool operator_req(int dx, int dy) {

    if (nodes[index].first.x + dx < 0 || nodes[index].first.x + dx >= M) {
        return false;
    }

    if (nodes[index].first.y + dy < 0 || nodes[index].first.y + dy >= N) {
        return false;
    }

    if (room[nodes[index].first.y + dy][nodes[index].first.x + dx] == 1) {
        return false;
    }

    for (auto i : nodes) {
        if (i.first.x == nodes[index].first.x + dx && i.first.y == nodes[index].first.y + dy) {
            return false;
        }
    }

    return true;
}

void bredth() {
    while (!(nodes[index].first.x == M - 1 && nodes[index].first.y == N - 1)) {

        if (operator_req(+1, 0)) {
            nodes.push_back({{nodes[index].first.x + 1, nodes[index].first.y + 0}, index});
            //cout << ">\n";
        }
        
        if (operator_req(-1, 0)) {
            nodes.push_back({{nodes[index].first.x - 1, nodes[index].first.y - 0}, index});
            //cout << "<\n";
        }
        
        if (operator_req(0, -1)) {
            nodes.push_back({{nodes[index].first.x - 0, nodes[index].first.y - 1}, index});
            //cout << "^\n";
        }
        
        if (operator_req(0, +1)) {
            nodes.push_back({{nodes[index].first.x + 0, nodes[index].first.y + 1}, index});
            //cout << "v\n";
        } 
        index++;
    }
}

void print(int i) {

    if (i != -1) {
        print(nodes[i].second);
        int dx = nodes[i].first.x - nodes[nodes[i].second].first.x;
        int dy = nodes[i].first.y - nodes[nodes[i].second].first.y;

        if (dx == 1) {
            cout << "E";
        }
        if (dx == -1) {
            cout << "W";
        }
        if (dy == 1) {
            cout << "S";
        }
        if (dy == -1) {
            cout << "N";
        }
    }
}

int main() {

    while (cin >> N >> M, N != 0) {

        nodes.clear();
        index = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%1d", &room[i][j]);        

        nodes.push_back({{0, 0}, -1});
        bredth();
        print(index);

        cout << endl;
    }
}