#include <vector>

using namespace std;

class Solution {
public:

    int dfs(int r, int c, vector<vector<bool>>& visited,
            vector<vector<int>>& grid, int num_rows, int num_cols)
    {
        if (r == num_rows || c == num_cols || r < 0 || c < 0 || grid[r][c] == 1 ||
            visited[r][c])
        {
            return 0;
        }
        if (r == num_rows-1 && c == num_cols-1)
        {
            return 1;
        }
        visited[r][c] = true;
        int sum = dfs(r+1, c, visited, grid, num_rows, num_cols)
                + dfs(r-1, c, visited, grid, num_rows, num_cols)
                + dfs(r, c+1, visited, grid, num_rows, num_cols)
                + dfs(r, c-1, visited, grid, num_rows, num_cols);
        visited[r][c] = false;

        return sum;
    }

    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        size_t num_rows = grid.size();
        size_t num_cols = grid[0].size();
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));

        return dfs(0, 0, visited, grid, num_rows, num_cols);

    }
};
