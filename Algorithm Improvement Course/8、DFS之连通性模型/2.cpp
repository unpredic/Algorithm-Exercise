#include <iostream>

using namespace std;

const int N = 30;

int n, m;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    g[x][y] = '#';
    int res = 1;
    
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (g[a][b] == '#') continue;
        g[a][b] == '#';
        res += dfs(a, b);
    }
    return res;
}

int main() {
    
    while (cin >> m >> n, m || n) {
        
        int x, y;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                cin >> g[i][j];
                if (g[i][j] == '@') x = i, y = j;
            }
        }
        cout << dfs(x, y) << endl;
    }
    
    return 0;
}