/*
字典树：
    0号点既是根节点，又是空节点
    son[][]存储树中每个节点的子节点
    cnt[]存储以每个节点结尾的单词数量
*/ 

template <typename T>
class PrefixTree {
private:
    static const int N = 1e5 + 10;
    vector<vector<int>> son(N, vector<int>(26));
    vector<int> cnt(cnt);
    int idx;
public:
    PrefixTree() {}

    // 插入一个字符串
    void insert(string str) {
        int p = 0;
        for (int i = 0; i < str.size(); i ++) {
            int u = str[i] - 'a';
            if (!son[p][u]) son[p][u] = ++ idx;
            p = son[p][u];
        }
        cnt[p] ++ ;
    }

    // 查询单个字符串出现的次数
    int query(string str){
        int p = 0;
        for (int i = 0; i < str.size(); i ++) {
            int u = str[i] - 'a';
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
};