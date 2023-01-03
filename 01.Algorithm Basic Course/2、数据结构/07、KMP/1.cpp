// 参考：https://blog.csdn.net/yyzsir/article/details/89462339
// 参考：https://www.zhihu.com/question/21923021
// 参考：https://www.bilibili.com/video/BV1jb411V78H?from=search&seid=9567658849506181801


//7
//p->abaabca
//13
//s->ababcabcacbab
//ne[0~7]->0,0,0,1,1,2,0,1

#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char p[N], s[M];

int main() {
    
    cin >> n >> p + 1 >> m >> s + 1;
    
    //求ne数组，从长度为2开始
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    
    //遍历一边模式串
    for (int i = 1, j = 0; i <= m; i ++ ) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n) {
            cout << i - n << " ";
            j = ne[j];
        }
    }
    
    return 0;
}