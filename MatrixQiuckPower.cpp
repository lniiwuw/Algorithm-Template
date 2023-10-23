template<typename T>
class MatrixQuickPower {
private:
    int n;
    MatrixQuickPower (int _n) :n(_n) {}
    static const int MOD = 1e9 + 7;

public:
    // 矩阵乘法
    vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b) {
        vector<vector<long long>> c(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    // 矩阵快速幂
    vector<vector<long long>> pow(vector<vector<long long>> &a, long long n) {
        vector<vector<long long>> res;
        // 初始化为单位矩阵
        for (int i = 0; i < res.size(); i++) {
            res[i][i] = 1;
        }
        for (; n; n /= 2) {
            if (n % 2) {
                res = multiply(res, a);
            }
            a = multiply(a, a);
        }
        return res;
    }
};