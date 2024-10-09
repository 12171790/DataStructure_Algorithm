#include <iostream>
#include <vector>

using namespace std;

int solution(const vector<vector<int>>& m) {
    int rows = m.size();
    int cols = m[0].size();

    vector<vector<int>> dp (rows, vector<int>(cols, 0));

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (x == 0 && y == 0) dp[y][x] = m[0][0];
            else if (y == 0) dp[y][x] = m[y][x] + dp[y][x - 1];
            else if (x == 0) dp[y][x] = m[y][x] + dp[y - 1][x];
            else dp[y][x] = m[y][x] + min(dp[y - 1][x], dp[y][x - 1]);
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    vector<vector<int>> v = {
        {2, 7, 5, 4},
        {5, 3, 6, 8},
        {7, 8, 7, 4},
        {8, 1, 9, 5}
    };

    cout << "Minimum cost : " << solution(v) << endl;
}