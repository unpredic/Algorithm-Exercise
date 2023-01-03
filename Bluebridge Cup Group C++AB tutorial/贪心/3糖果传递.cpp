#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n;
int a[N];

int main() {
    scanf("%d", &n);
    
    LL sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int avg = (int) (sum / n);
    //求减去平均值之后的数组的前缀和
    for (int i = 1; i <= n; i ++ ) {
        a[i] = a[i] - avg + a[i - 1];
    }
    
    sort(a + 1, a + n + 1);
    
    LL res = 0;
    for (int i = 1; i <= n; i ++ ) {
        res += abs(a[i] - a[(n + 1) / 2]);
    }
    
    cout << res << endl;
    
    return 0;
}