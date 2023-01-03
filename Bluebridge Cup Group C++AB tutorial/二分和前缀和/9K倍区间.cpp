#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, k;
LL a[N], s[N];
LL cnt[N]; // 余数是i的数有多少个

int main() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    
    LL res = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        res += cnt[s[i] % k];
        cnt[s[i] % k] ++ ;
    }
    
    cout << res << endl;
    
    return 0;
    
}