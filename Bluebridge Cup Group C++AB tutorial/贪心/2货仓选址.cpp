#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    
    sort(a, a + n);
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        res += abs(a[i] - a[n / 2]);
    }
    
    cout << res << endl;
    
    return 0;
    
}


// 错误写法：
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    
    sort(a, a + n);
    // 错误、应取个数的中间
    int loc = (a[n - 1] + a[0]) / 2;
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        res += abs(a[i] - loc);
    }
    
    cout << res << endl;
    
    return 0;
    
}