template <typename T = int, int inf = 0x3f3f3f3f>
class FenwickTree {
private:
    int n;
    vector<T> v;
    FenwickTree(int n) : n(n), v(n, inf) {}
public:
    void update(int x, T y) {
        x += 1;
        for (; x <= n; x += x & -x) {
            v[x - 1] = min(v[x - 1], y);
        }
    }
    
    T query(int x) {
        x = min(x, n - 1);
        T y = inf;
        x += 1;
        for (; x; x -= x & -x) {
            y = min(y, v[x - 1]);
        }
        return y;
    }
};