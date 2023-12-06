#include<bits/stdc++.h>

struct TreeAncestor {
    std::vector<int> depth;
    std::vector<std::vector<int>> pa;
    
    TreeAncestor(std::vector<std::pair<int, int>> &edges) {
        int n = edges.size() + 1;
        int m = 32 - __builtin_clz(n); // n 的二进制长度
        std::vector<std::vector<int>> g(n);
        for (auto [x, y]: edges) { // 节点编号从 0 开始
            g[x].push_back(y);
            g[y].push_back(x);
        }

        depth.resize(n);
        pa.resize(n, std::vector<int>(m, -1));
        std::function<void(int, int)> dfs = [&](int x, int fa) {
            pa[x][0] = fa;
            for (int y: g[x]) {
                if (y != fa) {
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++) {
            for (int x = 0; x < n; x++) {
                if (int p = pa[x][i]; p != -1) {
                    pa[x][i + 1] = pa[p][i];
                }
            }
        }
    }

    int get_kth_ancestor(int node, int k) {
        for (; k; k &= k - 1)
            node = pa[node][__builtin_ctz(k)];
        return node;
    }

    // 返回 x 和 y 的最近公共祖先（节点编号从 0 开始）
    int get_lca(int x, int y) {
        if (depth[x] > depth[y])
            std::swap(x, y);
        // 使 y 和 x 在同一深度
        y = get_kth_ancestor(y, depth[y] - depth[x]);
        if (y == x)
            return x;
        for (int i = pa[x].size() - 1; i >= 0; i--) {
            int px = pa[x][i], py = pa[y][i];
            if (px != py) {
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }
};