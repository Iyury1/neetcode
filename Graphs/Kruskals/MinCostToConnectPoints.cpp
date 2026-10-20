#include <vector>
#include <tuple>
#include <queue>
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

    int distance(vector<int>& p1, vector<int>& p2)
    {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        using T = tuple<int,int,int>; // cost, u, v

        priority_queue<T, vector<T>, greater<>> minHeap;

        for (size_t i = 0; i < points.size(); ++i)
        {
            for (size_t j = i + 1; j < points.size(); ++j)
            {
                minHeap.push({distance(points[i], points[j]), i, j});
            }
        }

        size_t count = 0;
        int cost = 0;
        size_t n = points.size();
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);
        vector<int> sizes(n, 1);
        while (count < n-1 && !minHeap.empty())
        {
            auto [w, u, v] = minHeap.top(); minHeap.pop();
            if (!unite(u,v, parents, sizes))
            {
                continue;
            }
            cost += w;
            count++;
        }
        return cost;
        
    }
};