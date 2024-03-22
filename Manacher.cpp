#include <bits/stdc++.h>
/**
 * Manacher算法：O(n)
 * d1[i] 表示以i为中心的长度为奇数的回文串的最大长度
 * d2[i] 表示以i为中心(字符串中心为[i - 1, i])的长度为偶数的回文串的最大长度
 * */ 
struct Manacher {
    std::vector<int> d1, d2;
    Manacher(std::string &s) {
        int n = s.size();
        d1.resize(n);
        d2.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

    bool PalindromeCheck (int l, int r) {
        int id = (r + l + 1) / 2;
        if ((r - l + 1) & 1) {
            return d1[id] >= (r - l + 2) / 2;
        } else {
            return d2[id] >= (r - l + 1) / 2;
        }
    }
};
