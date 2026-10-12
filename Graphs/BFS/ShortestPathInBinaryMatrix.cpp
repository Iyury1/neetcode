#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty() || grid[0][0] == 1)
        {
            return -1;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        int neighbors[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1},
                                {1,1}, {-1,1}, {-1,-1}, {1,-1}};

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));


        q.push({0,0});
        visited[0][0] = true;
        int length = 1;

        while (!q.empty())
        {
            int levelSize = static_cast<int>(q.size());
            for (int i = 0; i < levelSize; ++i)
            {
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if (r == rows-1 && c == cols-1)
                {
                    return length;
                }
                for (int j = 0; j < 8; ++j)
                {
                    int nr = r + neighbors[j][0];
                    int nc = c + neighbors[j][1];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || visited[nr][nc] || grid[nr][nc] == 1)
                    {
                        continue;
                    }

                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
            length++;
        }
        return -1;
    }
};