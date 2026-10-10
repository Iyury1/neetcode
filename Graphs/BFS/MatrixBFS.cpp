#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {

        if (grid.empty() || grid[0].empty() || grid[0][0] == 1) return -1;

        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({0,0});

        visited[0][0] = true;

        pair<int,int> neighbors[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        bool found = false;
        int length = 0;
        while (!q.empty() && !found)
        {
            int levelNodes = static_cast<int>(q.size());
            for (int i = 0; i < levelNodes; ++i)
            {
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if (r == rows-1 && c == cols-1)
                {
                    return length;
                }
                
                for (const auto& neighbor : neighbors)
                {
                    int nr = r + neighbor.first;
                    int nc = c + neighbor.second;
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || visited[nr][nc] || grid[nr][nc] == 1)
                    {
                        continue;
                    }
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }


            length += 1;
        }
        return -1;
    }
};
