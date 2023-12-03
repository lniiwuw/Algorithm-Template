#include <bits/stdc++.h>

struct SparseTable{
    int n;
    std::vector<std::vector<int>> dpmx, dpmn;
    std::vector<int> lg, v;

    SparseTable (std::vector<int> &a) : v(a){
        n = a.size();
        lg.resize(n + 2);
        lg[2] = 1;
        for (int i = 3; i <= n; i++) {
            lg[i] = lg[i/2] + 1;
        }

        dpmx.resize(n, std::vector<int> (32, INT32_MIN));
        dpmn.resize(n, std::vector<int> (32, INT32_MAX));
        for (int i = 0; i < n; i++) {
            dpmx[i][0] = dpmn[i][0] = v[i];
        }
        for (int j = 1; j < 30; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                dpmx[i][j] = std::max(dpmx[i][j - 1], dpmx[i + (1 << (j - 1))][j - 1]);
                dpmn[i][j] = std::min(dpmn[i][j - 1], dpmn[i + (1 << (j - 1))][j - 1]);            
            }
        }
    }

    int getmax(int l, int r) {
        int k = lg[r - l + 1];
        return std::max(dpmx[l][k], dpmx[r - (1 << k) + 1][k]);
    }

    int getmin(int l, int r) {
        int k = lg[r - l + 1];
        return std::min(dpmn[l][k], dpmn[r - (1 << k) + 1][k]);
    }
};