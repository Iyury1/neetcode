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

    bool _union(int x, int y, vector<int>& parent, vector<int>& size)
    {
        int px = find(x, parent), py = find(y, parent);
        if (px == py) return false;

        if (size[px] > size[py])
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
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector<int> size(n, 1);

        for (const auto& edge : edges)
        {
            if(_union(edge[0], edge[1], parent, size)) components--;
        }
        return components;
    }

};
