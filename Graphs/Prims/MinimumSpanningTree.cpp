#include <numeric>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {

        using T = tuple<int,int,int>; // {weight, node, parent}
        priority_queue<T, vector<T>, greater<>> minHeap;

        vector<vector<pair<int,int>>> adj(n); // {neightbor, weight}
        vector<bool> visited(n, false);

        for (const auto& e : edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        minHeap.push({0,0, -1});
        vector<T> mst;

        while (!minHeap.empty())
        {
            auto [w1, n1, parent] = minHeap.top(); minHeap.pop();
            if (visited[n1]) continue;

            visited[n1] = true;
            if (parent != -1) mst.push_back({w1, n1, parent});
            for (const auto& [n2, w2] : adj[n1])
            {
                if (!visited[n2])
                {
                    minHeap.push({w2, n2, n1});
                }
            }
        }

        if ((int)mst.size() != n-1) return -1;

        return accumulate(mst.begin(), mst.end(), 0, [](int acc, const T&e) { return acc + get<0>(e);});
    }
};