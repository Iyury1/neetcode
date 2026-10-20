#include <vector>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;

class Solution {
public:

    int find(int x, vector<int>& parents)
    {
        while (x != parents[x])
        {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    bool unite(int x, int y, vector<int>& parents, vector<int>& sizes)
    {
        int px = find(x, parents), py = find(y, parents);

        if (px == py) return false;

        if (sizes[px] > sizes[py])
        {
            parents[py] = px;
            sizes[px] += sizes[py];
        }
        else
        {
            parents[px] = py;
            sizes[py] += sizes[px];
        }

        return true;
    }

    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        
        if (edges.size() < n-1) return -1;
        using T = tuple<int,int,int>; // weights, n1, n2
        priority_queue<T, vector<T>, greater<>> minHeap;

        for (const auto& e : edges)
        {
            minHeap.push({e[2], e[0], e[1]});
        }
        
        vector<int> parents(n);        
        iota(parents.begin(), parents.end(), 0);
        vector<int> sizes(n, 1);

        vector<T> mst;

        while ((int)mst.size() < n && !minHeap.empty())
        {
            auto [w, u, v] = minHeap.top(); minHeap.pop();

            if (!unite(u,v, parents, sizes))
            {
                continue;
            }
            mst.push_back({w, u, v});
        }
        int sum = accumulate(mst.begin(), mst.end(), 0, [](int acc, const T& e){return acc + get<0>(e);});
        return mst.size() == n-1 ? sum : -1;
        
    }
};