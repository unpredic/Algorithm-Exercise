#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M];
bool st[N][N];

void bfs(int x, int y) {
    int hh = 0, tt = -1;
    q[++ tt] = {x, y};
    
    while (hh <= tt) {
        auto t = q[hh ++ ];

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int i = 0; i < 8; i ++ ) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && g[a][b] == 'W') {
                st[a][b] = true;
                q[++ tt] = {a, b};
            }
        }
    }
    
    
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) {
        scanf("%s", g[i]);
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                cnt ++ ;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}