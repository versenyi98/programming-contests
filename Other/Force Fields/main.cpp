#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define f first
#define s second

typedef pair<int, int> node;
typedef pair<double, pair<node, node>> edge;
typedef pair<double, pair<pair<int, int>, pair<int, int>>> query;

int number_of_nodes;
int number_of_queries;

vector<node> nodes;
priority_queue<edge> edges;
priority_queue<pair<int, int>> solved_query;
priority_queue<query> queries;          

map<node, int> which_tree;
map<int, vector<node>> nodes_in_tree;
int how_many_trees;

double dist(node a, node b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

int main() {

    cin >> number_of_nodes;
    how_many_trees = number_of_nodes;

    int x, y;
    for (int i = 0; i < number_of_nodes; i++) {
        cin >> x >> y;
        
        nodes.push_back({x, y});
        which_tree[{x, y}] = i;
        nodes_in_tree[i].push_back({x, y});

        for (int j = 0; j < i; j++) {
            edges.push({-dist(nodes[j], {x, y}), {{x, y}, nodes[j]}});
        }
    }

    cin >> number_of_queries;

    int type;
    double radius;
    for (int i = 0; i < number_of_queries; i++) {
        int city_a = 0, city_b = 0;
        cin >> type >> radius;
        if (type) cin >> city_a >> city_b;

        queries.push({-2*radius, {{type, i}, {city_b, city_a}}});
    }

    double worst;
    while (!edges.empty() && how_many_trees != 1) {

        edge current = edges.top();
        edges.pop();

        if (which_tree[current.s.f] == which_tree[current.s.s]) continue;

        double worst = current.f * -1;
        while (!queries.empty() && queries.top().f * -1 < worst) {
            query current_q = queries.top();
            queries.pop();

            if (current_q.s.f.f == 0) {
                solved_query.push({-current_q.s.f.s, how_many_trees});
            } else {
                solved_query.push({-current_q.s.f.s, which_tree[nodes[current_q.s.s.f]] == which_tree[nodes[current_q.s.s.s]]});
            }
        }

        int ow = which_tree[current.s.s];
        for (auto j : nodes_in_tree[ow]) {
            nodes_in_tree[which_tree[current.s.f]].push_back(j);
            which_tree[j] = which_tree[current.s.f];
        }
        nodes_in_tree[ow] = {};
        how_many_trees--;
    } 

    while (!queries.empty()) {
        query current_q = queries.top();
        queries.pop();

        if (current_q.s.f.f == 0) {
            solved_query.push({-current_q.s.f.s, how_many_trees});
        } else {
            solved_query.push({-current_q.s.f.s, which_tree[nodes[current_q.s.s.f]] == which_tree[nodes[current_q.s.s.s]]});
        }
    }

    while (!solved_query.empty()) {
        cout << solved_query.top().s << endl;
        solved_query.pop();
    }
}