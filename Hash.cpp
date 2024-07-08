#include <bits/stdc++.h>

/**
多项式字符串哈希（方便计算子串哈希值）
哈希函数 hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
pow_base[i] = base^i
前缀哈希值 pre_hash[i] = hash(s[:i])
*/
struct stringhash {
    int n, BASE;
    const int MOD = 1'070'777'777; 
    std::vector<int> pre_hash, pow_base;
 
    stringhash(std::string &text) {
        n = text.size();
        std::mt19937 gen{std::random_device{}()};
        BASE = std::uniform_int_distribution<>(8e8, 9e8)(gen); // 随机 base
        pow_base.resize(n + 1); 
        pre_hash.resize(n + 1); // 
        pow_base[0] = 1;
        for (int i = 0; i < n; i++) {
            pow_base[i + 1] = (long long) pow_base[i] * BASE % MOD;
            pre_hash[i + 1] = ((long long) pre_hash[i] * BASE + text[i]) % MOD;
        }
    }
    
    // 计算[l, r]的哈希值
    int RangeQuery (int l, int r) {
        assert(r < n);
        return ((pre_hash[r + 1] - (long long)pre_hash[l] * pow_base[r + 1 - l]) % MOD + MOD) % MOD;
    }

    int getHash (std::string &text) {
        int res = 0;
        for (char ch : text) {
            res = ((long long)res * BASE % MOD + ch) % MOD;
        }
        return res;
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