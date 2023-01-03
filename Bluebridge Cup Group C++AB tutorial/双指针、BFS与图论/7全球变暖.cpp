// Flood Fill 算法会把所有的连通块算出来(两种实现方式bfs\dfs)
// 分析：
// 第一步，求连通块个数
// 第二步，统计有多少个连通块会被淹没
// 思路：
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
char g[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void bfs(int x, int y, int &total, int &bound) {

    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        total ++ ;
        
        bool is_bound = false;
        for (int i = 0; i < 4; i ++ ) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < n && g[a][b] == '.') {
                is_bound = true;
            }
            if (a >= 0 && a < n && b >= 0 && b < n && !st[a][b] && g[a][b] == '#') {
                st[a][b] = true;
                q.push({a, b});
            }
        }
        if (is_bound) bound ++ ;
    }
    
}


int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);
    
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            if (!st[i][j] && g[i][j] == '#') {
                // 每个连通块中的陆地块数以及会被淹没的块数 if (total == bound) 连通块岛屿被淹没
                int total = 0, bound = 0; 
                bfs(i, j, total, bound);
                if (total == bound) cnt ++ ;
            }
        }
    }
    
    cout << cnt << endl;
    
    return 0;
    
}


