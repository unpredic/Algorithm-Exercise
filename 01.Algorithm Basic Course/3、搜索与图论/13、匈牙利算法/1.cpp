// 匹配：在图论中，一个「匹配」是一个边的集合，其中任意两条边都没有公共顶点。
// 最大匹配：一个图所有匹配中，所含匹配边数最多的匹配，称为这个图的最大匹配。
// 完美匹配：如果一个图的某个匹配中，所有的顶点都是匹配点，那么它就是一个完美匹配。

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) { // //如果女孩j没有男朋友，或者她原来的男朋友能够预定其它喜欢的女孩。配对成功
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    int res = 0;
    for (int i = 1; i <= n1; i ++ ) {
        memset(st, false, sizeof st);
        if (find(i)) res ++ ;
    }
    printf("%d\n", res);
    return 0;
}