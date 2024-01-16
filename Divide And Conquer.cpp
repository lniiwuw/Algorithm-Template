#include <bits/stdc++.h>
using i64 = long long;

// 分块/根号分治 
// cf1921F
void DivideAndConquer (int n, std::vector<int> &a) {
    int n;
    const int D = sqrt(n) + 1;  
    std::vector preSum(D, std::vector<i64>(n));
    std::vector divSum(D, std::vector<i64>(n));
    for (int x = 1; x < D; x++) {
        for (int i = 0; i < x; i++) {
            preSum[x][i] = a[i];
            divSum[x][i] = a[i];
        }
        for (int i = x; i < n; i++) {
            preSum[x][i] = preSum[x][i - x] + a[i];
            divSum[x][i] = divSum[x][i - x] + 1LL * a[i] * (i / x + 1);
        }
    }
}