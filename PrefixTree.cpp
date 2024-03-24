// 01trie find the max xor
#include<bits/stdc++.h>
const int N = 2e6 + 10;
struct PrefixTree{
    std::vector<std::array<int, 2>> tree;
    std::vector<int> cnt;
    int idx;
    PrefixTree (int sz) {
        tree.assign(sz, std::array<int, 2>{});
        cnt.assign(sz, 0);
        idx = 0;
    }
    void insert(int num) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            if (!tree[p][u]) tree[p][u] = ++ idx;
            p = tree[p][u];
            cnt[p] ++;
        }
    }
    void del(int num) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            p = tree[p][u];
            cnt[p] --;
        }
    }
    int find(int num) {
        int sum = 0, p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            u ^= 1;
            if (cnt[tree[p][u]]) {
                sum += 1 << i;
                p = tree[p][u];
            } else {
                p = tree[p][u ^ 1];
            }
        }
        return sum;
    }
    void clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j < 2; j++) tree[i][j] = 0;
        }
        idx = 0;
    }
} trie(N);
