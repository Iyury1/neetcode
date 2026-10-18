#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int distance(vector<int> p1, vector<int> p2)
    {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visited(n, false);

        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        int total = 0;
    
        for (int k = 0; k < n; ++k)
        {
            int u = -1;
            for (int i = 0; i < n; ++i)
            {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
            }
            visited[u] = true;
            total += dist[u];

            for (int v = 0; v < n; ++v)
            {
                if (!visited[v])
                {
                    dist[v] = min(dist[v], distance(points[u], points[v]));
                }
            }
        }        

        return total;
        
    }
};
