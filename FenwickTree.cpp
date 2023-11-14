template <typename T>
class FenwickTree {
private:
    int n;
    T inf;
    std::vector<T> v;
public:
    FenwickTree(int n, T inf) : n(n), inf(inf), v(n, inf) {}
    void update(int x, T y) {
        x += 1;
        for (; x <= n; x += x & -x) {
            v[x - 1] = std::min(v[x - 1], y);
        }
    }
    
    T query(int x) {
        x = std::min(x, n - 1);
        T y = inf;
        x += 1;
        for (; x > 0; x -= x & -x) {
            y = std::min(y, v[x - 1]);
        }
        return y;
    }
};