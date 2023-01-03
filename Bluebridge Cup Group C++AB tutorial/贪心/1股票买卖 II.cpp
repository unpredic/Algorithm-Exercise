// 对于每一次交易都可以转换为长度是一的交易的集合

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i ++ ) {
        if (a[i] - a[i - 1] > 0) {
            res += a[i] - a[i - 1];
        }
    }
    cout << res << endl;
}