// 分析： 建立n个节点的图来解决,最终会形成k个环
// 位置： 1 2 3 4 5
// 瓶子： 3 1 2 5 4
// 交换瓶子3和1相当于把瓶子所在得位置1和2得出边改变了
// 分情况：
// 交换同一个环内的瓶子：裂成两个环
// 交换不同环内的瓶子：合并成一个环
// 每次操作最多只能增加一个环,要从k个环增加到n个环至少需要n - k次

// 暴力O(n^2)
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] != i) {
            for (int j = i + 1; j <= n; j ++ ) {
                if (a[j] == i) {
                    swap(a[j], a[i]);
                    res ++ ;
                }
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}

// 不清楚为啥可以过
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        while (a[i] != i) {
            res ++ ;
            swap(a[i], a[a[i]]);
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}


#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
bool st[N]; // 判重数组,用来帮助我们找环

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    int k = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) {       // 如果当前点没有被找过
            k ++ ;        // 接下来把这个点全部能到的点标记一下,即找到这个点所在的环的全部点并标记
            for (int j = i; !st[j]; j = a[j]) {   
                st[j] = true;
            }
        }
    }
    
    cout << n - k << endl;
    
    return 0;
    
}