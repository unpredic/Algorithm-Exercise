// spfa算法是shortest path fastest algorithm的缩写。再通常情况下，
// 是一种比较高效的求解最短路的算法。spfa的本质是广度优先搜索，
// 将图所有的边都遍历一遍。平均时间复杂度是O(m)，最坏时间复杂度是O(mn)，其中m是图的边数。
// https://blog.csdn.net/qq_41729237/article/details/118580328
// https://blog.csdn.net/muxidreamtohit/article/details/7894298?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-7894298-blog-118580328.t5_refersearch_landing&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-7894298-blog-118580328.t5_refersearch_landing&utm_relevant_index=1

// 1sC++运算也只能运算 1e7 ~1e8之间
// 需要用循环队列来存取，因为每个点不一定只入队一次。
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
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
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}

int main() {
    
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++ ) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    
    int t = spfa();
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t << endl;
    
    return 0;
}