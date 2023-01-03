//宽搜一般有模板
//1.初始状态->queue
//2.while queue不空
//3.队头->t
//4.扩展t
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N], d[N][N];
PII q[N * N];

int bfs() {
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    while(hh <= tt) {
        auto t = q[hh ++ ];
        
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q[ ++ tt] = {x, y};
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {

    cin >> n >> m;
    
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            cin >> g[i][j];
        }
    }
    
    cout << bfs() << endl;
    
}


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];
int d[N][N];

int bfs() {
    memset(d, -1, sizeof d);
    d[1][1] = 0;
    
    queue<PII> q;
    q.push({1, 1});
    
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x && y && x <= n && y <= m && g[x][y] == 0 && d[x][y] == -1) {
                q.push({x, y});
                d[x][y] = d[t.first][t.second] + 1;
            }
        }
        
    }
    
    return d[n][m];
    
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];
        
    cout << bfs() << endl;
    
    return 0;
}