const int MOD = 1'000'000'007;
const int MOD = 998'244'353;
const int MX = 100'000;

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

// combination number template
long long fac[MX], inv_fac[MX];

auto init = [] {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int k) {
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}