template <typename T>
class SparseTable{
private:
    int n;
    std::vector<std::vector<T>> dpmx, dpmn;
    std::vector<int> lg;

public:
    SparseTable (std::vector<T> &a) {
        n = a.size();
        lg.resize(n + 2);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i/2] + 1;
        }

        int m = 33 - __builtin_clz(n);
        dpmx.resize(n, std::vector<T> (m));
        dpmn.resize(n, std::vector<T> (m));
        for (int i = 0; i < n; i++) {
            dpmx[i][0] = dpmn[i][0] = a[i];
        }
        for (int j = 1; j < m; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                dpmx[i][j] = std::max(dpmx[i][j - 1], dpmx[i + (1 << (j - 1))][j - 1]);
                dpmn[i][j] = std::min(dpmn[i][j - 1], dpmn[i + (1 << (j - 1))][j - 1]);            
            }
        }
    }

    T getmax(int l, int r) {
        int k = lg[r - l + 1];
        return std::max(dpmx[l][k], dpmx[r - (1 << k) + 1][k]);
    }

    T getmin(int l, int r) {
        int k = lg[r - l + 1];
        return std::min(dpmn[l][k], dpmn[r - (1 << k) + 1][k]);
    }
};