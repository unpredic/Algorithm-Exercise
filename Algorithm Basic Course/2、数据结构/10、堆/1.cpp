// 堆是一颗完全二叉树    STL里面的堆就是优先队列
// 一维数组存储(下标从一开始推荐)
// x的左儿子是2x
// x的右儿子是2x+1
// 1、插入一个数 heap[++size]=x;up(size);
// 2、求集合当中的最小值 heap[1];
// 3、删除最小值 heap[1]=heap[size];size--;down(1);
// 4、删除任意一个元素 heap[k] = heap[size];size--;down(k);up(k);
// 5、修改任意一个元素 heap[k] = x;down(x);up(x);
// 五种操作都可以用down、up来解决

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], mysize;

void up(int u) {
    while (u / 2 > 0 && h[u] < h[u / 2]) {
        swap(h[u], h[u / 2]);
        u = u >> 1;
    }
}

void down(int u) {
    int t = u;
    if (u * 2 <= mysize && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= mysize && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    mysize = n;
    
    for (int i = n / 2; i >= 1; i -- ) down(i);
    
    while (m -- ) {
        cout << h[1] << " ";
        h[1] = h[mysize -- ];
        down(1);
    }
    
    return 0;
}