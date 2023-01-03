// 将所有订单按照时间顺序排序
// 从前往后枚举每个订单：注意：每次处理一批订单(时间点相同店铺id也相同)
// score[i]: 第i个店铺当前的优先级
// last[i]:第i个店铺上一次有订单的时刻
// st[i]:第i个店铺当前是否处于优先缓存中
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m, T;    // n加外卖店 m条订单信息 t时刻有多少家外卖店在优先缓存
int score[N], last[N];
bool st[N];
PII order[N];

int main() {
    
    cin >> n >> m >> T;
    
    for (int i = 0; i < m; i ++ ) scanf("%d%d", &order[i].first, &order[i].second);
    
    sort(order, order + m); // pair是一个双关键字排序
    
    for (int i = 0; i < m;) {
        // 每次处理一批时间点相同店铺id也相同的订单
        int j = i;
        while (j < m && order[j] == order[i]) j ++ ;
        int ts = order[i].first, id = order[i].second, cnt = j - i; // cnt:时间点相同店铺id也相同的个数
        i = j;
        
        // 处理t时刻前的
        score[id] -= ts - last[id] - 1;
        if (score[id] < 0) score[id] = 0;
        if (score[id] <= 3) st[id] = false;
        // 处理t时刻的
        score[id] += cnt * 2;
        if (score[id] > 5) st[id] = true;
        // 记录最后订单时刻
        last[id] = ts;
    }
    
    for (int i = 1; i <= n; i ++ ) {
        if (last[i] < T) {
            score[i] -= T - last[i];
            if (score[i] <= 3) st[i] = false;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (st[i]) res ++ ;
    }
    
    cout << res << endl;
    
    return 0;
    
}