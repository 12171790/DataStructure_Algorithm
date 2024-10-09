#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 6;
bool gVisited[N] = {};

void dfs_recursion(const vector<vector<int>>& v, int s) {

    if (gVisited[s]) {
        return;
    }

    gVisited[s] = true;
    cout << s << ", ";

    for (int i : v[s]) {
        dfs_recursion(v, i);
    }

}

vector<int> dfs(const vector<vector<int>>& v, int s) {
    vector<bool> visited(v.size(), false);
    vector<int> visit_order;
    stack<int> stk;
    stk.push(s);

    while(!stk.empty()) {
        int k = stk.top();
        stk.pop();

        if (visited[k]) continue;

        visited[k] = true;
        visit_order.push_back(k);

        for (int i : v[k]) {
            if (!visited[i]) {
                stk.push(i);
            }
        }
    }

    return visit_order;

}

vector<int> bfs(const vector<vector<int>>& v, int s) {
    vector<bool> visited(v.size(), false);
    vector<int> visit_order;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int k = q.front();
        q.pop();

        if (visited[k]) continue;

        visited[k] = true;
        visit_order.emplace_back(k);

        for (int i : v[k]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }

    return visit_order;
}


int main() {

    vector<vector<int>> adj_list = {
        {1, 3, 4},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {0, 1, 3},
        {2}
    };

    dfs_recursion(adj_list, 0);
    cout << endl;

    auto dfs_order = dfs(adj_list, 0);
    auto bfs_order = bfs(adj_list, 0);

    cout << "dfs : ";
    for (auto i : dfs_order) {
        cout << i << ",";
    }
    cout << endl;

    cout << "bfs : ";
    for (auto i : bfs_order) {
        cout << i << ",";
    }
    cout << endl;
}