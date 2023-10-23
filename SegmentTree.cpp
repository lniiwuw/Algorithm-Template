template <typename T> 
class SegmentTree {
private:
    vector<T> tree, lazy;

public:
    SegmentTree(vector<T> s) {
        int n = s.size();
        tree.resize(n << 2, 0);
        lazy.resize(n << 2, 0);
        build(1, n, 1, s);
    }

    void pushup (int rt) {
        tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
    }

    void pushdown (int rt) {}

    void build(int l, int r, int rt, vector<T> &s) {
        if (l == r) {
            tree[rt] = s[l - 1];
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, rt << 1, s);
        build(mid + 1, r, rt << 1 | 1, s);
        pushup(rt);
    }

    T getmax(int l, int r, int L, int R, int rt) {
        if (l <= L && R <= r) {
            return tree[rt];
        }
        int ans = -1, mid = l + r >> 1;
        if (L >= mid) {
            ans = max(ans, getmax(l, mid, L, R, rt << 1));
        }
        if (mid < R) {
            ans = max(ans, getmax(mid + 1, r, L, R, rt << 1 | 1));
        }
        return ans;
    }
};