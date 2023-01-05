class Solution {
public:
    int n, m;
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int k) {
        if (x >= n || x < 0 || y >= m || y < 0) return false;
        if (board[x][y] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[x][y] = '\0';
        bool res = dfs(board, word, x - 1, y, k + 1) ||
                    dfs(board, word, x, y + 1, k + 1) ||
                    dfs(board, word, x + 1, y, k + 1) ||
                    dfs(board, word, x, y - 1, k + 1);
        board[x][y] = word[k];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};