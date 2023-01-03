#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int T, n, m, x, y, cnt;
bool st[N][N];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// 直接记录当前走了几个格子,如果已经遍历完所有的格子,就将答案加一.
void dfs(int a, int b, int step) {
    if (step == n * m) {
        cnt ++ ;
        return;
    }
    
    st[a][b] = true;
    for (int i = 0; i < 8; i ++ ) {
        int ax = a + dx[i], by = b + dy[i];
        if (ax < 0 || ax >= n || by < 0 || by >= m) continue;
        if (st[ax][by]) continue;
        dfs(ax, by, step + 1 );
        st[ax][by] = false;
    }
    
}

int main() {
    
    cin >> T;
    while (T -- ) {
        cin >> n >> m >> x >> y;
        
        cnt = 0;
        memset(st, false, sizeof st);
        dfs(x, y, 1);
        
        cout << cnt << endl;
    }
    
    return 0;
}