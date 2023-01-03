// 多重背包问题优化算法
// 不能直接用完全背包问题的优化方法
// 二进制优化方式： 
/*
例子:要求在一堆苹果选出n个苹果。我们传统的思维是一个一个地去选，选够n个苹果就停止。这样选择的次数就是n次
二进制优化思维就是：现在给出一堆苹果和10个箱子，选出n个苹果。将这一堆苹果分别按照1,2,4,8,16,.....512
分到10个箱子里，那么由于任何一个数字x ∈[1,1024]都可以从这10个箱子里的苹果数量表示出来，
但是这样选择的次数就是 ≤10次 。
*/
#include <iostream>

using namespace std;

// 0<N≤1000
// 0<V≤2000
// 0<vi,wi,si≤2000

const int N = 12010, M = 2010; // 逐一枚举最大是N*logS

int n, m;
int v[N], w[N], s[N];
int f[M];

int main() {
    cin >> n >> m;
    
    int cnt = 0; // 分组的组别
    for (int i = 1; i <= n; i ++ ) {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1; // 组别里的个数
        while (k <= s) {
            cnt ++ ; // 组别先增加
            v[cnt] = a * k; // 整体体积
            w[cnt] = b * k; // 整体价值
            s = s - k;
            k = k * 2;  // 组别里的个数增加
        }
        // 剩余的一组
        if (s > 0) {
            cnt ++ ;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt; // 枚举次数正式有个数变成组别数
    
    // 01背包一维优化
    for (int i = 1; i <= n; i ++ ) {
        for (int j = m; j >= v[i]; j -- ) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
    
}