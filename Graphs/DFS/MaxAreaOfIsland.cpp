#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int num_rows, int num_cols)
    {
        if (r < 0 || c < 0 || r >= num_rows || c >= num_cols || visited[r][c] || grid[r][c] != 1)
        {
            return 0;
        }
        visited[r][c] = true;
        int sum = 1;
        sum += dfs(grid, r-1, c, visited, num_rows, num_cols);
        sum += dfs(grid, r+1, c, visited, num_rows, num_cols);
        sum += dfs(grid, r, c-1, visited, num_rows, num_cols);
        sum += dfs(grid, r, c+1, visited, num_rows, num_cols);
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int num_rows = static_cast<int>(grid.size());
        int num_cols = static_cast<int>(grid[0].size());
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        int ret = 0;
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                ret = max(ret, dfs(grid, i, j, visited, num_rows, num_cols));
            }
        }
        return ret;
    }
};


class IterativeSolution {
public:


    int dfs(int sr, int sc, int rows, int cols, vector<vector<int>>& grid)
    {
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        stack<pair<int,int>> s;

        grid[sr][sc] = 0;
        s.push({sr,sc});
        int size = 0;
        while (!s.empty())
        {
            auto [r, c] = s.top();
            s.pop();
            size++;
            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] == 0)
                {
                    continue;
                }
                grid[nr][nc] = 0;
                s.push({nr,nc});
            }
        }
        return size;
    

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = static_cast<int>(grid.size()), cols = static_cast<int>(grid[0].size());

        int ret = 0;

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 1)
                {
                    ret = max(ret, dfs(r,c, rows, cols, grid));
                }
            }
        }
        return ret;
    }
};