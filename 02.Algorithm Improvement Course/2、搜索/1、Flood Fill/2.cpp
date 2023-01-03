#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 55, M = N * N;

int m, n;
int g[N][N];
PII q[M];
bool st[N][N];

int bfs(int x, int y) {
    int hh = 0, tt = -1;
    q[++ tt] = {x, y};
    st[x][y] = true;
    
    int area = 0;
    while (hh <= tt) {
        auto t = q[hh ++ ];
        area ++ ;
        // 西：1 北：2 东：4 南：8 注意遍历顺序要一致,方便判断墙
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i ++ ) { // 西：0 北：1 东：2 南：3
            int a = t.first + dx[i], b = t.second + dy[i]; // 判断能不能向i代表的方向走
            if (g[t.first][t.second] >> i & 1) continue;
            if (a < 0 || a >= m || b < 0 || b >= n) continue;
            if (st[a][b]) continue;
            st[a][b] = true;
            q[++ tt] = {a, b};
            
        }
        
    }
    
}

int main() {
    
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            scanf("%d", &g[i][j]);
        }
    }
    
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (!st[i][j]) {
                ans = max(ans, bfs(i, j));
                cnt ++ ;
            }
        }
    }
    printf("%d\n%d\n", cnt, ans);
    return 0;
}