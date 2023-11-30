#include <bits/stdc++.h>

// strongly connected component
// tarjan algorithm  O(n + m)
struct SCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stack;
    std::vector<int> dfn, low, belong;
    int cur, cnt;
    
    SCC() {}
    SCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        belong.assign(n, -1);
        stack.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stack.push_back(x);
        
        for (auto y : adj[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (belong[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stack.back();
                belong[y] = cnt;
                stack.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return belong;
    }
};

// kosaraju algothrim O(n + m)
struct kosaraju {
    int n, sccCnt;
    std::vector<std::vector<int>> e, re;
    std::vector<bool> vis;
    std::vector<int> belong, stack;
    
    kosaraju() {}
    kosaraju(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        this->sccCnt = 0;
        e.assign(n, {});
        re.assign(n, {});
        vis.resize(n);
        belong.assign(n, -1);
    }
    
    void addEdge(int u, int v) {
        e[u].push_back(v);
        re[v].push_back(u);
    }

    void dfs1(int u) {
        vis[u] = true;
        for (int v : e[u])
            if (!vis[v])
                dfs1(v);
        stack.push_back(u);
    }

    void dfs2(int u) {
        belong[u] = sccCnt;
        for (int v : re[u])
            if (belong[v] == -1)
                dfs2(v);
    }

    std::vector<int> work() {
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs1(i);
        for (int i = n - 1; i >= 0; --i) {
            if (belong[stack[i]] == -1) {
                dfs2(stack[i]);
                sccCnt ++;
            }
        }
        return belong;
    }
};