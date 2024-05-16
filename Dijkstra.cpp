#include <bits/stdc++.h>

using i64 = long long;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Dijkstra {
    std::vector<std::vector<std::pair<int, i64>>> adj;
    int n;
    
    Dijkstra(int n) {
        this->n = n;
        adj.resize(n);
    }

    void add (int u, int v, i64 w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void addSingle (int u, int v, i64 w) {
        adj[u].push_back({v, w});
    }
    
    std::vector<i64> work(int s) {
        std::vector<i64> dis(n, inf);
        std::vector<bool> vis(n);
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>> > q;
            
        dis[s] = 0;
        q.push({0, s});
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (vis[u]) continue;    
            vis[u] = true;
            for (auto [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};