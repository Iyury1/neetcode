#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        vector<int> distance(n+1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n+1);

        for (const auto& t : times)
        {
            adj[t[0]].push_back({t[1], t[2]});
        }

        distance[k] = 0;
        minHeap.push({0,k});
        int seen = 0;
        int last = 0;
        while (!minHeap.empty())
        {
            auto [w1, n1] = minHeap.top(); minHeap.pop();
            if (w1 > distance[n1]) continue;

            for (const auto& [n2, w2] : adj[n1])
            {
                if (distance[n1] + w2 < distance[n2])
                {
                    distance[n2] = distance[n1] + w2;
                    minHeap.push({distance[n2], n2});
                }
            }
            seen++; last = w1;
        }

        return seen == n  ? last : -1;

    }
};
