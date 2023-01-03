#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N], b[N], c[N];
int as[N], cs[N];   //as[]记录在A中由多少个数小于B[i]   cs[]记录在C中由多少个数大于B[i]
int cnt[N], s[N];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]), a[i] ++ ;
    for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]), b[i] ++ ;
    for (int i = 0; i < n; i ++ ) scanf("%d", &c[i]), c[i] ++ ;
    
    // 求as
    for (int i = 0; i < n; i ++ ) cnt[a[i]] ++ ;
    for (int i = 1; i < N; i ++ ) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i ++ ) as[i] = s[b[i] - 1];
    
    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);
    for (int i = 0; i < n; i ++ ) cnt[c[i]] ++ ;
    for (int i = 1; i < N; i ++ ) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i ++ ) cs[i] = s[N - 1] - s[b[i]];
    
    // 从b组开始枚举
    LL res = 0;
    for (int i = 0; i < n; i ++ ) {
        res += (LL) as[i] * cs[i];
    }
    
    cout << res << endl;
    
    return 0;
    
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int a[N], b[N], c[N];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]);
    for (int i = 0; i < n; i ++ ) scanf("%d", &c[i]);
    
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    
    LL res = 0;
    for (int i = 0; i < n; i ++ ) {
        // upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)
        // 算法返回一个非递减序列[first, last)中第一个大于val的位置。
        // lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)
        // 算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
        LL x = (lower_bound(a, a + n, b[i]) - a);
        LL y = n - (upper_bound(c, c + n, b[i]) - c + 1) + 1;
        res += x * y;
    }
    
    cout << res << endl;
    
    return 0;
    
}