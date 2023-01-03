#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;

int n, k;
char g[N][N];
bool st[N][N];
int ax, ay, bx, by;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool dfs(int x, int y) {
    if (g[x][y] == '#') return false; //如果起点或者终点有一个不能通行(为#)，则看成无法办到。
    if (x == bx && y == by) return true;
    
    st[x][y] = true;
    for (int i = 0; i < 4; i ++ ) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;
        if (dfs(a, b)) return true;
    }
    return false;
}

int main() {
    
    cin >> k;
    while (k -- ) {
        memset(st, 0, sizeof st);
        cin >> n;
        for (int i = 0; i < n; i ++ ) {
            cin >> g[i];
        }
        cin >> ax >> ay >> bx >> by;
        if (dfs(ax, ay)) puts("YES");
        else puts("NO");
    }
    
    return 0;
}