#include <bits/stdc++.h>
// TreeHash 可判断树是否同构
struct TreeHash {
    using i64 = long long;
    using ull = unsigned long long;
    const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();
    std::vector<bool> sym;
    std::vector<ull> hash;
    TreeHash(){}
    TreeHash(std::vector<std::vector<int>> &adj, int root = 0) {
        int n = adj.size();
        sym.resize(n);
        hash.resize(n);
        dfs(root, -1, adj);
    }
    ull xorshift(ull x) {
        x ^= mask;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        x ^= mask;
        return x;
    }
    void dfs (int u, int pre, std::vector<std::vector<int>> &adj) {
        hash[u] = 1;
        ull xor_value = 0;
        for (int to : adj[u]) {
            if (to == pre) {
                continue;
            }
            dfs(to, u, adj);
            hash[u] += xorshift(hash[to]);
            xor_value ^= xorshift(hash[to]);
        }

        if (!xor_value) {
            sym[u] = true;
        } else {
            for (int to : adj[u]) {
                if (to == pre) {
                    continue;
                }
                if (xor_value == xorshift(hash[to]) && sym[to]) {
                    sym[u] = true;
                    break;
                }
            }
        }
    }
};
