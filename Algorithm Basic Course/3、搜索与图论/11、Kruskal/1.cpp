#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    
    // 重载小于号运算符,按w排序
    bool operator< (const Edge &W)const {
        return w < W.w;
    } 
}edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);
    
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ ) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
        
    }
    
    if (cnt < n - 1) return INF; // n个节点的树只有n - 1个节点
    return res;
    
}

int main() {
    
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    
    int t = kruskal();
    if (t == INF) puts("impossible");
    else printf("%d\n", t);
    
    return 0;
}