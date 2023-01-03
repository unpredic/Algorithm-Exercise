#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N]; //防止队列中存储重复的点
int cnt[N]; 

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

bool spfa() {
    
    queue<int> q;
    
    for (int i = 1; i <= n; i ++ ) {
        st[i] = true;
        q.push(i);
    }
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
    
}

int main() {
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    
    while (m -- ) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    if (spfa()) puts("Yes");
    else puts("No");
    
    return 0;
}