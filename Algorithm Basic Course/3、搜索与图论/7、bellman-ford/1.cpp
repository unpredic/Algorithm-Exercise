#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge {
    int a, b, c;
} edges[M];

void bellman_ford() {
    
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++ ) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++ ) {
            int a = edges[j].a, b = edges[j].b, c = edges[j].c;
            dist[b] = min(dist[b], backup[a] + c);
        }
    }
    
}

int main() {
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    
    bellman_ford();
    
    if (dist[n] > 0x3f3f3f3 / 2) puts("impossible");
    else cout << dist[n] << endl;
    
    return 0;
}