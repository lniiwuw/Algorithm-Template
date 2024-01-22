/*求[0, r]的最小值*/
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

/*求[0, r]的最大值*/
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
            v[x - 1] = std::max(v[x - 1], y);
        }
    }
    
    T query(int x) {
        x = std::min(x, n - 1);
        T y = inf;
        x += 1;
        for (; x > 0; x -= x & -x) {
            y = std::max(y, v[x - 1]);
        }
        return y;
    }
};

/*求[l, r]的和*/
template <typename T>
class FenwickTree {
private:
    int n;
    std::vector<T> v;
public:
    FenwickTree(int n) : n(n), v(n, 0) {}
    void update(int x, T y) {
        x += 1;
        for (; x <= n; x += x & -x) {
            v[x - 1] += y;
        }
    }
    
    T query(int x) {
        x = std::min(x, n - 1);
        T sum = 0;
        x += 1;
        for (; x > 0; x -= x & -x) {
            sum += v[x - 1];
        }
        return sum;
    }

    T rangQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};