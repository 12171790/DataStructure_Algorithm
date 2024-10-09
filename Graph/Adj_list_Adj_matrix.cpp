#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> get_adj_list(const vector<vector<int>>& adj_matrix) {

    vector<vector<int>> adj_list(adj_matrix.size());

    for (int u = 0; u < adj_matrix.size(); u++) {
        for (int v = 0; v < adj_matrix[u].size(); v++) {
            if (adj_matrix[u][v] == 1) {
                adj_list[u].push_back(v);
            }
        }
    }

    return adj_list;

}

int main() {

    vector<vector<int>> adj_matrix = {
        {0, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    vector<vector<int>> adj_list = get_adj_list(adj_matrix);

    for (const auto& i : adj_list) {
        for (const auto j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }

}