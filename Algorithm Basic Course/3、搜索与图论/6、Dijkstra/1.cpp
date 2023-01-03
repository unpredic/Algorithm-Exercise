#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];//稠密图使用邻接矩阵存储
int dist[N];//记录每个节点距离起点的距离
bool st[N];//true表示已经确定最短距离

int dijkstra() {
    //所有节点距离起点的距离初始化为无穷大
    memset(dist, 0x3f, sizeof dist);
    //起点距离自己的距离为零
    dist[1] = 0;
    //迭代n次，每次可以确定一个点到起点的最短路
    for (int i = 0; i < n; i ++ ) {
        // 一开始t的赋值是-1
        // 如果t没有被更新，
        // 那么要更新一下t
        int t = -1;
        for (int j = 1; j <= n; j ++ ) {
            //1.不在s集合，并且
            //如果没有更新过，则进行更新， 或者发现更短的路径，则进行更新
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        //2.加入到s集合中
        st[t] = true;
        //3.用t更新其他点的距离
        for (int j = 1; j <= n; j ++ ) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    // 如果起点到达不了n号节点，则返回-1
    if (dist[n] == 0x3f3f3f3f) return -1;
    // 返回起点距离n号节点的最短距离
    return dist[n];
}

int main() {
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof g);  //所有节点之间的距离初始化为无穷大
    // 0x3f 0x3f3f3f3f 的区别？
    // memset 按字节赋值，所以memset 0x3f 就等价与赋值为0x3f3f3f3f
    
    for (int i = 0; i < m; i ++ ) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    
    cout << dijkstra() << endl;
    
    return 0;
    
}