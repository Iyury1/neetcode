#include <vector>
#include <utility>
#include <stack>

using namespace std;


class Solution {
public:
    void dfs(int sr, int sc, int rows, int cols, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        stack<pair<int,int>> s;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        s.push({sr,sc});
        visited[sr][sc] = true;
        vector<pair<int,int>> path;
        path.push_back({sr,sc});
        bool escapes = false;
        while (!s.empty())
        {
            auto [r, c] = s.top();
            s.pop();
            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr == rows || nc == cols ||
                    board[nr][nc] == 'X' || visited[nr][nc])
                {
                    continue;
                }
                if (nr == 0 || nr == rows-1 || nc == 0 || nc == cols-1)
                {
                    escapes = true;
                }
                s.push({nr,nc});
                visited[nr][nc] = true;
                path.push_back({nr,nc});
            }
        }
        if (!escapes)
        {
            for (auto [r, c] : path)
            {
                board[r][c] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 1; r < rows-1; ++r)
        {
            for (int c = 1; c < cols-1; ++c)
            {
                if (board[r][c] == 'O' && !visited[r][c])
                {
                    dfs(r, c, rows, cols, board, visited);
                }
            }
        }

    }
};


class Solution_Reverse {
public:

    void dfs(int sr, int sc, int rows, int cols, vector<vector<char>>& board)
    {
        
        stack<pair<int,int>> s;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        s.push({sr,sc});
        board[sr][sc] = 'T';

        while (!s.empty())
        {
            auto [r, c] = s.top();
            s.pop();
            for (const auto& [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr == rows || nc == cols
                    || board[nr][nc] != 'O')
                {
                    continue;
                }
                board[nr][nc] = 'T';
                s.push({nr,nc});

            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        
        int rows = board.size(), cols = board[0].size();

        for (int r = 0; r < rows; ++r)
        {
            if (board[r][0] == 'O') dfs(r, 0, rows, cols, board);
            if (board[r][cols-1] == 'O') dfs(r, cols-1, rows, cols, board);
        }

        for (int c = 0; c < cols; ++c)
        {
            if (board[0][c] == 'O') dfs(0, c, rows, cols, board);
            if (board[rows-1][c] == 'O') dfs(rows-1, c, rows, cols, board);
        }

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }

    }
};


class Solution_Reverse_Lambda {
public:

    void solve(vector<vector<char>>& board) {
        
        int rows = board.size(), cols = board[0].size();
        stack<pair<int,int>> s;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        auto seed = [&](int r, int c)
        {
            if (board[r][c] == 'O')
            {
                board[r][c] = 'T';
                s.push({r,c});
            }
        };

        for (int r = 0; r < rows; ++r)
        {
            if (board[r][0] == 'O') seed(r, 0);
            if (board[r][cols-1] == 'O') seed(r, cols-1);
        }

        for (int c = 0; c < cols; ++c)
        {
            if (board[0][c] == 'O') seed(0, c);
            if (board[rows-1][c] == 'O') seed(rows-1, c);
        }

        while (!s.empty())
        {
            auto [r, c] = s.top();
            s.pop();
            for (auto [dr, dc] : dirs)
            {
                int nr = r+dr, nc = c+dc;
                if (nr < 0 || nc < 0 || nr == rows || nc == cols || board[nr][nc] != 'O')
                {
                    continue;
                }
                board[nr][nc] = 'T';
                s.push({nr,nc});
            }
        }

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == 'T')
                {
                    board[r][c] = 'O';
                }
            }
        }

    }
};