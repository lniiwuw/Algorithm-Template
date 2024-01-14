#include <bits/stdc++.h>

using ull = unsigned long long;
struct stringhash {
    int n;
    ull base = 29;
    std::vector<ull> hash, p;
 
    stringhash(std::string &text) {
        n = text.size();
        hash.resize(n + 1);
        p.resize(n);
        hash[0] = 0, p[0] = 1;
        for(int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + (text[i] - 'a' + 1);
        }
        for(int i = 1; i < n;i++) {
            p[i] = p[i - 1] * base;
        }
    }
    
    ull RangeQuery (int l, int r) {
        assert(r <= n);
        return hash[r + 1] - hash[l] * p[r + 1 - l];
    }

    ull getHash (std::string &text) {
        ull res = 0;
        for (char ch : text) {
            res = res * base + (ch - 'a' + 1) ;
        }
    }
};