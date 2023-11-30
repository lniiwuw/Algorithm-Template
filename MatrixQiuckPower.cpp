template<typename T>
class MatrixQuickPower {
private:
    int row;
    static const int MOD = 1e9 + 7;

public:
    MatrixQuickPower(int _n) : row(_n) {}

    // Matrix multiplication
    std::vector<std::vector<T>> multiply(const std::vector<std::vector<T>> &a, const std::vector<std::vector<T>> &b) {
        int m = a.size();
        std::vector<std::vector<T>> ret(m, std::vector<T>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    ret[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return ret;
    }

    // Matrix quick power
    std::vector<std::vector<T>> quickPow(std::vector<std::vector<T>> &a, T n) {
        std::vector<std::vector<T>> res(row, std::vector<T>(row));
        // Initialize as the identity matrix
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
