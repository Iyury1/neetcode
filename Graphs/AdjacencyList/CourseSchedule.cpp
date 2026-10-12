#include <vector>

using namespace std;

class Solution {
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
