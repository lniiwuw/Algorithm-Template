template <typename T>
class KMP {
public: 
    KMP() {}
    
    // 求match数组，即next数组
    std::vector<int> calc_max_match(string s) {
        std::vector<int> match(s.length());
        int c = 0;
        for (int i = 1; i < s.length(); i++) {
            char v = s[i];
            while (c && s[c] != v) {
                c = match[c - 1];
            }
            if (s[c] == v) {
                c++;
            }
            match[i] = c;
        }
        return match;
    }

    // 返回 text 中出现了多少次 pattern（允许 pattern 重叠）
    int kmp_search(string text, string pattern) {
        std::vector<int> match = calc_max_match(pattern);
        int match_cnt = 0, c = 0;
        for (int i = 0; i < text.length(); i++) {
            char v = text[i];
            while (c && pattern[c] != v) {
                c = match[c - 1];
            }
            if (pattern[c] == v) {
                c++;
            }
            if (c == pattern.length()) {
                match_cnt++;
                c = match[c - 1];
            }
        }
        return match_cnt;
    }
};