// 1.将两个集合合并
// 2.询问两个元素是否在一个集合当中

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    while (m -- ) {
    	// 推荐这种，不管一个字符还是多个字符都用%s
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M') {
            p[find(a)] = find(b);
        } else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}