#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution_Recursive {
public:

    bool dfs(int c, const vector<vector<int>>& courses, vector<int>& currentPath)
    {
        if (currentPath[c] == 1)
        {
            return false; // Cycle detected
        }
        if (currentPath[c] == 2)
        {
            return true; // Already verified
        }

        currentPath[c] = 1;
        for (const auto p : courses[c])
        {
            if (!dfs(p, courses, currentPath))
            {
                return false;
            } 
        }
        currentPath[c] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        for (const auto& edge : prerequisites)
        {
            courses[edge[0]].push_back(edge[1]);
        }

        vector<int> currentPath(numCourses, 0);
        for (int c = 0; c < numCourses; ++c)
        {
            if (dfs(c, courses, currentPath) == false) return false;
        }
        return true;
    }
};


class Solution_Iterative {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if (prerequisites.empty()) return true;
        vector<char> state(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& e : prerequisites)
        {
            adj[e[1]].push_back(e[0]);
        }
        stack<pair<int, size_t>> s;


        for (int start = 0; start < numCourses; ++start)
        {
            if (state[start] != 0) continue;

            state[start] = 1;
            s.push({start, 0});
            while (!s.empty())
            {
                auto& [u, i] = s.top();
                if (i == adj[u].size())
                {
                    state[u] = 2;
                    s.pop();
                    continue;
                }

                int v = adj[u][i++];
                if (state[v] == 1) return false;
                if (state[v] == 0) {
                    state[v] = 1;
                    s.push({v,0});
                }

            }
        }
        return true;
    }
};
