#include <bits/stdc++.h>
// const int MOD = 1'000'000'007;
const int MOD = 998'244'353;

long long q_pow(long long x, long long n) {
    long long res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

class Comb {
private:
    int n, MOD;
    std::vector<long long> _fac;
    std::vector<long long> _invfac;
    std::vector<long long> _inv;
public:
    Comb(int MOD) : n{0}, _fac{1}, _invfac{1}, _inv{0}, MOD(MOD) {}
    Comb(int MOD, int n) : Comb(MOD) {
        init(n);
    }
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i % MOD;
        }
        _invfac[m] = q_pow(_fac[m], MOD - 2);
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i % MOD;
            _inv[i] = _invfac[i] * _fac[i - 1] % MOD;
        }
        n = m;
    }
    
    long long fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    long long invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    long long inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    long long C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) % MOD * invfac(n - m) % MOD;
    }
};