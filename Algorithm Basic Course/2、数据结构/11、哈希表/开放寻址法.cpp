// 关于0x3f3f3f3f(0x四个3f)：https://blog.csdn.net/tcherry/article/details/37606277
// puts输出一串字符串后，会自动换行，不需要再加一个\n，因为它是自动换行的，多加一个换行会造成输出格式错误。
// 还需注意：gets前一般要加一个getchar，应为可能有上一次输入后的换行符被gets吸收。

#include <iostream>
#include <cstring>

using namespace std;

//开放寻址法一般开 数据范围的 2~3倍, 这样大概率就没有冲突了
//大于数据范围的第一个质数
const int N = 200003;
const int null = 0x3f3f3f3f;

int h[N];
//线性探测
int find(int x){
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x){
        t ++;
        if (t == N) t = 0;
    }
    return t;
}

int main(){
    memset(h, 0x3f, sizeof h);
    
    int n;
    cin >> n;
    while (n -- ){
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'I') h[find(x)] = x;
        else {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
