#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
int g[N][N];
PII pre[N][N];
PII q[N * N];

void bfs(int x, int y) {
    int hh = 0, tt = -1;
    q[++ tt] = {x, y};
    
    memset(pre, -1, sizeof pre);
    pre[x][y] = {0, 0};
    
    while (hh <= tt) {
        auto t = q[hh ++];
        
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++ ) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (pre[a][b].first != -1 || g[a][b] == 1) continue;
            q[++ tt] = {a, b};
            pre[a][b] = t;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            scanf("%d", &g[i][j]);
        }
    }
    
    bfs(n - 1, n - 1); // 从右下角开始搜索
    
    PII end(0, 0); // 初始化end变量
    while (true) {
        printf("%d %d\n", end.first, end.second);
        if (end.first == n - 1 && end.second == n - 1) break;
        end = pre[end.first][end.second];
    }
    
    return 0;
}