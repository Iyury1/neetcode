#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double, int>, vector<pair<double,int>>> maxHeap;

        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> probability(n, 0.0);

        probability[start_node] = 1.0;
        maxHeap.push({1.0, start_node});

        while (!maxHeap.empty())
        {
            auto [w1, n1] = maxHeap.top(); maxHeap.pop();
            if (n1 == end_node) return probability[n1];
            if (w1 < probability[n1]) continue;

            for (const auto& [n2, w2] : adj[n1])
            {
                if (probability[n1] * w2 > probability[n2])
                {
                    probability[n2] = probability[n1] * w2;
                    maxHeap.push({probability[n2], n2});
                }
            }
        }

        return probability[end_node];
    }
};