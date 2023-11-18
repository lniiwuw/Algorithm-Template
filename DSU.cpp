#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

/*带权并查集*/
struct DSU {
    std::vector<int> f, siz;
    std::vector<i64> d;
    DSU(int n) : f(n), siz(n, 1), d(n) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        if (x != f[x]) {
            int pre = f[x];
            f[x] = leader(f[x]);
            d[x] += d[pre];
        }
        return f[x];
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y, int w) {
        int prex = leader(x), prey = leader(y);
        if (prex == prey) {
            return d[x] - d[y] == w;
        }
        siz[prex] += siz[prey];
        f[prey] = prex;
        d[prey] = d[x] - w - d[y];
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
