#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> PIPII;

const int N = 110;

int l, r, c;
char g[N][N][N];
int d[N][N][N];
// 向北，向南，向东，向西，向上或向下
int dx[] = {-1, 0, 1, 0, 0, 0}, dy[] = {0, 1, 0, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

void bfs(int x1, int y1, int z1, int x2, int y2, int z2) {
    memset(d, -1, sizeof d);
    
    g[z1][x1][y1] = '#';
    g[z2][x2][y2] = '.';
    
    queue<PIPII> q;
    q.push({z1, {x1, y1}});
    
    d[z1][x1][y1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i ++ ) {
            int x = t.second.first + dx[i], y = t.second.second + dy[i], z = t.first + dz[i];
            if (x >= 0 && x < r && y >= 0 && y < c && z >= 0 && z < l && g[z][x][y] == '.') {
                d[z][x][y] = d[t.first][t.second.first][t.second.second] + 1;
                q.push({z, {x, y}});
                g[z][x][y] = '#';
            }
        }
        
    }
    if (d[z2][x2][y2] == -1) cout << "Trapped!" << endl;
    else {
        printf("Escaped in %d minute(s).\n", d[z2][x2][y2]);
    }
}

int main() {
    
    int x1, y1, z1, x2, y2, z2;
    
    while (cin >> l >> r >> c, l || r || c) {
        for (int k = 0; k < l; k ++ ) {
            for (int i = 0; i < r; i ++ ) {
                for (int j = 0; j < c; j ++ ) {
                    cin >> g[k][i][j];
                    if (g[k][i][j] == 'S') x1 = i, y1 = j, z1 = k;
                    if (g[k][i][j] == 'E') x2 = i, y2 = j, z2 = k;
                }
            }
        }
        
       bfs(x1, y1, z1, x2, y2, z2);
        
    }
    
    return 0;
    
}