#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110, M = 210 << 1;

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

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[t] + w[i] < dist[j]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) q.push(j);
                st[j] = true;
            }
        }
        
    }
    
    int res = dist[1];
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] == 0x3f3f3f3f) return -1;
        res = max(res, dist[i]);
    }
    return res;
}

int main() {
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while (m -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    
    int t = spfa();
    cout << t << endl;
    
    return 0;
}