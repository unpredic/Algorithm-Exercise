#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], tr[N];    // tree的缩写

int lowbit(int x) {
    return x&-x;
}

// 在x位置加v
void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        tr[i] += v;
    }
}

// 求前x个数前缀和
int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) {
        res += tr[i];
    }
    return res;
}

int main() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    // 原始数组求树状数组
    for (int i = 1; i <= n; i ++ ) add(i, a[i]);
    
    while (m -- ) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k) {
            add(x, y);
        } else {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}










#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int w[N];

struct Node {
    int l, r, sum;
}tr[N * 4];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

// 从第u层开始在区间[l, r]上初始化线段树
void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[l]};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }    
    
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) tr[u].sum += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &w[i]);
    }
    build(1, 1, n);
    
    while (m -- ) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k) {
            modify(1, a, b);
        } else {
            cout << query(1, a, b) << endl;
        }
    }
    
}