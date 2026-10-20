#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);

        vector<vector<int>> adj(numCourses);
        for (const auto& e : prerequisites) adj[e[1]].push_back(e[0]);

        vector<int> ret;
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
                    ret.push_back(u);
                    continue;
                }

                int v = adj[u][i++];
                if (state[v] == 1)
                {
                    return {};
                }
                if (state[v] == 0)
                {
                    state[v] = 1;
                    s.push({v, 0});
                }
            }

        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};