#include <unordered_map>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, std::greater<pair<long long,int>>> minHeap;
        vector<long long> distance(n, LLONG_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for (const auto& e : edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }

        distance[src] = 0;
        minHeap.push({0, src});
        while (!minHeap.empty())
        {
            auto [w1, n1] = minHeap.top(); minHeap.pop();
            if (w1 > distance[n1]) continue;

            for (const auto& [n2, w2] : adj[n1])
            {
                if (distance[n2] > distance[n1] + w2)
                {
                    distance[n2] = distance[n1] + w2;
                    minHeap.push({distance[n2],n2});
                }
            }
 
        }
        unordered_map<int,int> ret;
        for (int i = 0; i < distance.size(); ++i)
        {
            ret[i] = (distance[i] == LLONG_MAX) ? -1 : (int)distance[i];
        }
        return ret;
    }
};


class Solution_Map {
public:

    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_map<int,int> distance;
        vector<vector<pair<int,int>>> adj(n);

        for (const auto& e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }

        minHeap.push({0, src});
        while (!minHeap.empty()) {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();
            if (!distance.try_emplace(n1, w1).second) continue;

            for (const auto& [n2, w2] : adj[n1])
            {
                if (distance.find(n2) == distance.end())
                {
                    minHeap.push({w1 + w2, n2});

                }
            }

        }

        for (int i = 0; i < n; i++)
        {
            distance.try_emplace(i, -1);  // unreachable nodes
        }

        return distance;
    }
};