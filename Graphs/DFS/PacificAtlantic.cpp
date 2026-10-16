#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:

    void dfs(int sr, int sc, int rows, int cols,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited)
    {
        if (visited[sr][sc]) return;
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        stack<pair<int,int>> s;
        visited[sr][sc] = true;
        s.push({sr,sc});

        while (!s.empty())
        {
            auto [r, c] = s.top();
            s.pop();
            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr == rows || nc == cols||
                    heights[nr][nc] < heights[r][c] || visited[nr][nc])
                {
                    continue;
                }
                visited[nr][nc] = true;
                s.push({nr,nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; ++c)
        {
            dfs(0, c, rows, cols, heights, pacific);
            dfs(rows-1, c, rows, cols, heights, atlantic);
        }

        for (int r = 0; r < rows; ++r)
        {
            dfs(r, 0, rows, cols, heights, pacific);
            dfs(r, cols-1, rows, cols, heights, atlantic);
        }

        vector<vector<int>> ret;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (pacific[r][c] && atlantic[r][c])
                {
                    ret.push_back({r,c});
                }
            }
        }
        return ret;
    }
};