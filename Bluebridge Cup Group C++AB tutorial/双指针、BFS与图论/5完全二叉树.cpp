// 以每一层第一个数判断是否小于等于n(推荐)

// 以每一层最后一个数判断是否小于等于n,最后还得判断是否还有一层(不推荐)
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    int h = 1;
    LL res = 0;
    int i;
    // 在程序中不能使用 2^i, 建议使用位运算(不管移多少位时间复杂度都是O(1)的) 2 << i - 1
    for (i = 1; pow(2, i) - 1 <= n; i ++ ) {
        LL sum = 0; // 这里是有问题的, 数组中存在负数,但好像还是可以过
        for (int j = pow(2, i - 1); j < pow(2, i); j ++ ) {
            sum += a[j];
        }
        if (sum > res) {
            res = sum;
            h = i;
        }
    }
    LL sum = 0;
    for (int j = pow(2, i - 1); j <= n; j ++ ) {
        sum += a[j];
    }
    if (sum > res) {
        h = i;
    }
    
    cout << h << endl;
    
    return 0;
    
}


#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    LL maxs = -1e18;
    int h = 0;
    
    // d 表示第几层, i表示第d层的第一个数
    for (int d = 1, i = 1; i <= n; i *= 2, d ++ ) {
        LL s = 0;
        for (int j = i; j < i + (1 << (d - 1)) && j <= n; j ++ ) {
            s += a[j];
        }
        if (s > maxs) {
            maxs = s;
            h = d;
        }
    }
    
    cout << h << endl;
    
    return 0;
    
}