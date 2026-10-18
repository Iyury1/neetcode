# Dijkstra Notes

## The relaxation check

Start every node at infinity and the source at 0. When popping node `u`, try to improve each neighbor `v`:

$$
\text{if } \; d[u] + w(u,v) < d[v] \; \text{ then } \; d[v] \leftarrow d[u] + w(u,v)
$$

```cpp
vector<long long> dist(n, LLONG_MAX);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
dist[src] = 0;                         // don't forget this
pq.push({0, src});

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;         // stale entry, skip
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

- Every node is already in `dist`. `LLONG_MAX` means "not reached yet", so the first time a node is reached, the check always passes.
- `dist[u] + w` never overflows, because `u` is only processed once `dist[u]` is finite. This holds only if `dist[src] = 0` is set.
- `std::priority_queue` has no decrease-key, so old entries for a node stay in the heap. The `d > dist[u]` check discards them.
- Any node still at `LLONG_MAX` at the end is unreachable.
- Use `long long` unless the worst path, about `(n - 1) * max_weight`, clearly fits in `int`.

## Time complexity

Binary heap (lazy deletion, as above):

$$
O\big((V + E)\log V\big)
$$

The heap can hold up to $$E$$ entries, but $$\log E \le \log V^2 = 2\log V$$, so this is the same bound.

Other variants:

| Version | Time | Best for |
|---|---|---|
| Binary heap / `priority_queue` | $$O(E \log V)$$ | Sparse graphs, most problems |
| `std::set` (decrease-key) | $$O(E \log V)$$ | Bounding the queue at $$V$$ |
| Array scan, no heap | $$O(V^2)$$ | Dense graphs, $$E \approx V^2$$ |
| Fibonacci heap | $$O(E + V \log V)$$ | Theory, rarely used in practice |

## Bounding the queue at V with `set`

A `std::set` replaces the heap. `begin()` is the minimum, and any element can be erased, which gives a real decrease-key: remove the node's old entry and insert the new one.

```cpp
vector<long long> dist(n, LLONG_MAX);
set<pair<long long,int>> st;           // {distance, node}
dist[src] = 0;
st.insert({0, src});

while (!st.empty()) {
    auto [d, u] = *st.begin();
    st.erase(st.begin());
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            if (dist[v] != LLONG_MAX)
                st.erase({dist[v], v});    // decrease-key
            dist[v] = dist[u] + w;
            st.insert({dist[v], v});
        }
    }
}
```

- Each node appears at most once, so the set never holds more than $$V$$ entries.
- No stale check is needed, since whatever is popped is always current.
- It has the same $$O(E \log V)$$ bound, but in practice it is usually slower than `priority_queue`. A red-black tree allocates a node per insert, while a heap is a contiguous array.

## The dense-graph case

When the graph is dense ($$E \approx V^2$$), the heap version costs $$O(V^2 \log V)$$. Dropping the heap and scanning for the closest unvisited node is faster:

```cpp
vector<long long> dist(n, LLONG_MAX);
vector<bool> done(n, false);
dist[src] = 0;

for (int iter = 0; iter < n; iter++) {
    int u = -1;
    for (int i = 0; i < n; i++)                      // O(V) scan for min
        if (!done[i] && (u == -1 || dist[i] < dist[u]))
            u = i;
    if (dist[u] == LLONG_MAX) break;                 // rest unreachable
    done[u] = true;
    for (auto [v, w] : adj[u])
        if (dist[u] + w < dist[v])
            dist[v] = dist[u] + w;
}
```

The minimum scans cost $$V$$ rounds of $$V$$ each, and every edge is relaxed once in total:

$$
O(V^2) + O(E) = O(V^2)
$$

The array version wins roughly when

$$
E \log V > V^2 \quad\Longleftrightarrow\quad E \gtrsim \frac{V^2}{\log V}
$$

Typical signals are an adjacency-matrix input or a complete graph, such as "connect all points" problems.

## Negative edge weights

**No version of Dijkstra handles negative edge weights**, including the $$O(V^2)$$ one. Dijkstra assumes a node's distance is final once it is popped or selected. A negative edge found later could still shorten that path.

Use **Bellman-Ford** instead. It relaxes every edge $$V - 1$$ times:

$$
O(VE)
$$

One extra pass that still improves some distance means the graph has a negative cycle.
