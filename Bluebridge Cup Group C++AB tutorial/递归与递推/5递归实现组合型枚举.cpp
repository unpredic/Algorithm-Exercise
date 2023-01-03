// 递归实现组合型枚举
#include <iostream>

using namespace std;

const int N = 30;

int n, m;
int path[N];

void dfs(int u, int start) {
    if (u == m) {
        for (int i = 0; i < m; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return;
    }
    
    for (int i = start; i <= n; i ++ ) {
        path[u] = i;
        dfs(u + 1, i + 1);
        // path[u] = 0;
    }
    
}

int main() {
    scanf("%d%d", &n, &m);
    
    dfs(0, 1);
    
    return 0;
    
}

#include <iostream>

using namespace std;

const int N = 30;

int n, m;
bool st[N];
int path[N];

void dfs(int u, int start) {
    if (u == m) {
        for (int i = 0; i < m; i ++ ) {
            printf("%d ", path[i]);
        }
        puts("");
        return;
    }
    
    for (int i = start; i <= n; i ++ ) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1, i);
            st[i] = false;
        }
    }
    
}

int main() {
    scanf("%d%d", &n, &m);
    
    dfs(0, 1);
    
    return 0;
    
}