#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {


        const size_t n = graph.size();

        vector<int> states(n, 0);

        for (size_t start = 0; start < n; ++start)
        {
            if (states[start] != 0) continue;
            states[start] = 1;

            stack<pair<int,size_t>> s;
            s.push({start, 0});

            while (!s.empty())
            {
                auto& [u, i] = s.top();

                if (i == graph[u].size())
                {
                    int node = u;
                    if (states[node] == 1) states[node] = 2;
                    s.pop();
                    if (!s.empty() && states[node] == 3)
                    {
                        states[s.top().first] = 3;
                    }
                    continue;
                }

                int v = graph[u][i++];
                if (states[v] == 1 || states[v] == 3)
                {
                    states[u] = 3;
                    // cycle detected
                }
                if (states[v] == 0)
                {
                    s.push({v, 0});
                    states[v] = 1;
                }
            }


        }

        vector<int> safe;
        for (size_t i = 0; i < n; ++i)
        {
            if (states[i] == 2)
            {
                safe.push_back(i);
            }
        }
        return safe;
    }
};
