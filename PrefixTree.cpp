// 01trie find the max xor
const int N = 2e6 + 10;
int tree[N][2], cnt[N];
int idx = 0;

struct PrefixTree{
    void insert(int num) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            if (!tree[p][u]) tree[p][u] = ++ idx;
            p = tree[p][u];
            cnt[p] ++;
        }
    }

    void del(int num) {
        int p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            p = tree[p][u];
            cnt[p] --;
        }
    }

    int find(int num) {
        int sum = 0, p = 0;
        for (int i = 20; i >= 0; i--) {
            int u = (num >> i) & 1;
            u ^= 1;
            if (cnt[tree[p][u]]) {
                sum += 1 << i;
                p = tree[p][u];
            } else {
                p = tree[p][u ^ 1];
            }
        }
        return sum;
    }
};
