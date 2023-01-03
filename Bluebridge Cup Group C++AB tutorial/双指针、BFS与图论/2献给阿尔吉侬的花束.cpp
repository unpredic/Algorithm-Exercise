#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 210;

int t;
int d[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char g[N][N];

void bfs(int x1, int y1, int x2, int y2, int r, int c) {
    
    memset(d, -1, sizeof d);
    
    // printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, r, c);
    
    queue<PII> q;
    q.push({x1, y1});
    d[x1][y1] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < r && x >= 0 && y < c && y >= 0 && g[x][y] == '.' && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
            if (x < r && x >= 0 && y < c && y >= 0 && g[x][y] == 'E' && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        
    }
    
    if (d[x2][y2] == -1) cout << "oop!" << endl;
    else cout << d[x2][y2] << endl;
    
}

int main() {
    cin >> t;
    
    while (t -- ) {
        int r, c;
        cin >> r >> c;
        
        int x1, y1, x2, y2;
        for (int i = 0; i < r; i ++ ) {
            for (int j = 0; j < c; j ++ ) {
                cin >> g[i][j];
                if (g[i][j] == 'S') x1 = i, y1 = j;
                if (g[i][j] == 'E') x2 = i, y2 = j;
            }
        }
        
        bfs(x1, y1, x2, y2, r, c);
        
    }
    
    return 0;
    
}