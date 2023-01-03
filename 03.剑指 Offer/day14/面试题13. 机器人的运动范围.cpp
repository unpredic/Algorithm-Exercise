class Solution {
public:
    int count = 0, m, n;
    int getSum(int x, int y) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
    void dfs(int x, int y, int k, vector<vector<bool>> &st) {
        if (getSum(x, y) > k) return;
        count ++ ;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n) continue;
            if (st[a][b]) continue;
            dfs(a, b, k, st);
        }
    }
    int movingCount(int m1, int n1, int k) {
        m = m1, n = n1;
        vector<vector<bool>> st(m1, vector<bool>(n1, false));
        dfs(0, 0, k, st);
        return count;
    }
};