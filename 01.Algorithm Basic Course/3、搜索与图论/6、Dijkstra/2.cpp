#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010, M = 150010;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        
        if (st[ver]) continue; // 有重边，会多次加入该点到队列，虽然不影响结果，但可能会超时
        st[ver] = true;
        
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j] && w[i] + distance < dist[j]) {
                dist[j] = w[i] + distance;
                heap.push({dist[j], j});
            }
        }
        
    }
    
    return dist[n];
    
}

int main() {
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while (m -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    int t = dijkstra();
    if (t == 0x3f3f3f3f) puts("-1");
    else cout << t << endl;
    
    return 0;
}