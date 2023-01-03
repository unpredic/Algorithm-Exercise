// 朴素dijkstra算法
// time:229ms
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2510;

int T, C, Ts, Te;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(int x, int y) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    
    for (int i = 0; i < T; i ++ ) {
        int t = -1;
        for (int j = 1; j <= T; j ++ ) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        
        st[t] = true;
        for (int j = 1; j <= T; j ++ ) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return dist[y];
}

int main() {
    
    memset(g, 0x3f, sizeof g);
    
    cin >> T >> C >> Ts >> Te;
    while (C -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    
    int t = dijkstra(Ts, Te);
    cout << t << endl;
    return 0;
}

// 堆优化dijkstra算法
// time:37ms
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
// 需要特别注意这是无向图,边的数量要乘2,教训
const int N = 2510, M = 6210 << 1;

int T, C, Ts, Te;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dijkstra(int x, int y) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, x});
    
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j] && distance + w[i] < dist[j]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[y];
}

int main() {
    
    memset(h, -1, sizeof h);
    
    cin >> T >> C >> Ts >> Te;
    while (C -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    
    int t = dijkstra(Ts, Te);
    cout << t << endl;
    return 0;
}

// spfa算法
// time:29ms
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2510, M = 6210 << 1;

int T, C, Ts, Te;
int h[N],e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int spfa(int x, int y) {
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    
    queue<int> q;
    q.push(x);
    st[x] = true;
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[t] + w[i] < dist[j]) {
                dist[j] = w[i] + dist[t];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[y];
}

int main() {
    
    memset(h, -1, sizeof h);
    
    cin >> T >> C >> Ts >> Te;
    while (C -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    
    int t = spfa(Ts, Te);
    cout << t << endl;
    return 0;
}