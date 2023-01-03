// 维护一个字符串集合,高效存储和查找字符串

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], idx; // cnt[i]:以节点i结尾的字符串的个数 下标是0的节点既是根节点又是空节点
char str[N];

void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

int query(char *str) {
    int p = 0;
    for (int i = 0; str[i]; i ++ ) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d", &n);
    while (n -- ) {
        char op[2];
        scanf("%s%s", &op, &str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    return 0;
}