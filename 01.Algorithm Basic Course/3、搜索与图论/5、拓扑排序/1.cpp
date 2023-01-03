#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N];//队列存储层次遍历序列
int d[N];//存储i号节点的入度

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

bool topsort() {
    int hh = 0, tt = -1;
    
    for (int i = 1; i <= n; i ++ ) {
        if (!d[i]) {
            q[ ++ tt] = i;
        }
    }
    
    while (hh <= tt) {
        int t = q[hh ++ ];
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (-- d[j] == 0) {
                q[++tt] = j;
            }
        }
        
    }
    
    return tt == n - 1;
    
}


int main() {
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < m; i ++ ) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y] ++ ;
    }
    
    if (!topsort()) {
        puts("-1");
    } else {
        for (int i = 0; i < n; i ++ ) cout << q[i] << " ";
        puts("");
    }
    
    return 0;
    
}