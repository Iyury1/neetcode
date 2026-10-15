#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    int find(int x, vector<int>& parent)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y, vector<int>& parent, vector<int>& size)
    {
        int px = find(x, parent), py = find(y, parent);
        if (px == py)
        {
            return false;
        }
        if (size[px] >= size[py])
        {
            parent[py] = px;
            size[px] += size[py];
        }
        else
        {
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = static_cast<int>(edges.size());
        vector<int> parent(n+1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> size(n+1, 1);

        for (auto& edge : edges)
        {
            if (!unite(edge[0], edge[1], parent, size))
            {
                return edge;
            }
        }
        return {};
    }
};
