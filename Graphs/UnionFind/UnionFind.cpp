#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
    int components;
    vector<int> parent;
    vector<int> size;
public:

    UnionFind(int n) : parent(n), size(n,1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool isSameComponent(int x, int y) {
        return (find(x) == find(y));
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int px = find(x), py = find(y);
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
        components--;
        return true;
    }

    int getNumComponents() {
        return this->components;
    }
};
