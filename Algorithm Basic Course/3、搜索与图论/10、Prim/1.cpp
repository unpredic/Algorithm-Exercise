// 联系：Dijkstra算法是更新到起始点的距离，Prim是更新到集合S的距离
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    dist[1] = 0;
    
    for (int i = 0; i < n; i ++ ) {
        int t = -1;
        for (int j = 1; j <= n; j ++ ) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        
        // 如果孤立点，直返输出不能，然后退出
        if (dist[t] == INF) return INF;
        
        res += dist[t];
        st[t] = true;
        
        for (int j = 1; j <= n; j ++ ) {
            if (!st[j]) {
                dist[j] = min(dist[j], g[t][j]);
            }
        }
    }
    return res;
}

int main() {
    
    memset(g, 0x3f, sizeof g);
    
    cin >> n >> m;
    while (m -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        g[y][x] = g[x][y] = min(g[x][y], z);
    }
    
    int t = prim();
    if (t == INF) puts("impossible");
    else cout << t << endl;
    
    return 0;
}