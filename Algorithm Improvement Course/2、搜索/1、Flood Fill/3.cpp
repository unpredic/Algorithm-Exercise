#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n;
int h[N][N];
PII q[M];
bool st[N][N];

void bfs(int x, int y, bool& has_higher, bool& has_lower) {
    int hh = 0, tt = -1;
    q[++ tt] = {x, y};
    st[x][y] = true;
    
    while (hh <= tt) {
        auto t = q[hh ++ ];
        
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < 8; i ++ ) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (h[a][b] != h[t.first][t.second]) {
                if (h[a][b] > h[t.first][t.second]) has_higher = true;
                else has_lower = true;
            } else if (!st[a][b]) {
                q[++ tt] = {a, b};
                st[a][b] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            scanf("%d", &h[i][j]);
        }
    }
    
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (!st[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak ++ ; //当has_higher为false时，说明没有比i,j大的边界,此时i,j为山峰
                if (!has_lower) valley ++ ; 
            }
        }
    }
    printf("%d %d", peak, valley);
    return 0;
}