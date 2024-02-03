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

// 自定义unordered_map哈希函数
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

std::unordered_map<int, int, custom_hash> mp;