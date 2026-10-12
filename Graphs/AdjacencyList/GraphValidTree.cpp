#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> tree_nodes;
        
        if (static_cast<int>(edges.size()) != n-1)
        {
            return false;
        }
        vector<vector<int>> g(n);
    
        for (const auto& edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);     
        }

        stack<int> s;
        tree_nodes.insert(0);
        s.push(0);
        while(!s.empty())
        {
            int node = s.top();
            s.pop();

            for (const auto& neighbor : g[node])
            {
                auto [it, unique] = tree_nodes.insert(neighbor);
                if (unique) {
                    s.push(neighbor);
                }

            }
        }
        int tree_size = static_cast<int>(tree_nodes.size());
        return (tree_size == n);
    }
};
