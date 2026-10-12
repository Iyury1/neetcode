#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
        {
            return -1;
        }

        int rows = static_cast<int>(grid.size());
        int cols = static_cast<int>(grid[0].size());

        queue<pair<int,int>> q;

        int numFresh = 0;

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 1)
                {
                    numFresh += 1;
                }
                if (grid[r][c] == 2)
                {
                    q.push({r,c});
                }
            }
        }

        int length = 0;

        int neighbors[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty() && numFresh > 0)
        {
            int levelSize = static_cast<int>(q.size());
            for (int i = 0; i < levelSize; ++i)
            {
                pair<int,int> curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for (int j = 0; j < 4; ++j)
                {
                    int nr = r + neighbors[j][0];
                    int nc = c + neighbors[j][1];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] != 1)
                    {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    numFresh--;
                    q.push({nr,nc});
                }
            }
            length++;
        }

        if (numFresh > 0)
        {
            return -1;
        }
        return length;

    }
};
