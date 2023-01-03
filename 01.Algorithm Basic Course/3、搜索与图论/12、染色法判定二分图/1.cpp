// 一个图是二分图当且仅当图中不含奇数环
// 思路：dfs
// 1、染色可以使用1和2区分不同颜色，用0表示未染色。
// 2、遍历所有点，每次将未染色的点进行dfs, 默认染成1或者2
// 3、判断某个点是否染色失败，染色失败则不是二分图，否则为二分图。
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

bool dfs(int u, int color) {
    st[u] = color;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) { // 如果j节点没有被染色
            if (!dfs(j, 3 - color)) { // 给j节点染另一种颜色
                return false;
            }
        } else if (st[j] == color) return false; // 相邻节点染了同一种颜色
    }
    
    return true;
    
}

int main() {
    
    memset(h, -1, sizeof h);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) {
            if (!dfs(i, 1)) { // 染 1 
                flag = false;
                break;
            }
        }
    }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}