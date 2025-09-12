/* 777 */
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
    Edge(int from, int to, int weight) : u(from), v(to), w(weight) {}
};

struct Node {
    int u, cst;
    Node(int node, int cost) : u(node), cst(cost) {}

    // max-heap
    bool operator<(const Node& other) const { return cst > other.cst; };

    // min-heap
    // bool operator<(const Node& other) const { return cst < other.cst; };
};

const int MAX_N = 2e6 + 5, INF = 1e18 + 5;
int N, M, parent[MAX_N], dist[MAX_N];
vector<pair<int, int>> g[MAX_N];  // adj list : g[u] is list of {v, w}
bitset<MAX_N> vis;

void add_edge(int u, int v, int w = 1, bool dir = false) {
    g[u].emplace_back(v, w);
    if (!dir) {
        g[v].emplace_back(u, w);
    }
}

void build_graph(const vector<Edge>& edges, bool dir = false) {
    for (auto& e : edges) {
        add_edge(e.u, e.v, e.w, dir);  // (from, to, weight, isDirected)
    }
    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
        dist[i] = INF;
    }
}

// O(E * log V) for sparse graphs using min-heap/PQ
vector<int> dijkstra(int src) {
    auto cmp = [](const Node& a, const Node& b) { return a.cst > b.cst; };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

    pq.push(Node(src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int u = node.u, cst = node.cst;
        if (dist[u] < cst) continue;  // skip stale entries during relaxation
        for (auto& [v, w] : g[u]) {
            int ncst = cst + w;
            if (ncst < dist[v]) {
                dist[v] = ncst;
                pq.push(Node(v, ncst));
            }
        }
    }

    return vector<int>(dist + 1, dist + N + 1);
}

void solve() {
    cin >> N >> M;
    vector<Edge> edges;
    for (int u, v, i = 0; i < M; ++i) {
        int w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    build_graph(edges, true);

    vector<int> dists = dijkstra(1);
    for (int x : dists) cout << x << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    solve();
}