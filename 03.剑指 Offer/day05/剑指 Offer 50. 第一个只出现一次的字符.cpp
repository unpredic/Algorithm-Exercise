// 哈希表
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> umap;
        for (auto c : s) {
            umap[c] = umap.find(c) == umap.end();
        }
        for (auto c : s) {
            if (umap[c]) return c;
        }
        return ' ';
    }
};