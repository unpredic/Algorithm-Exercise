

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII; // ts, id

const int N = 1e5 + 10;

int n, d, k;
int cnt[N]; // id 为 i 的在某一时间段的点赞数量
bool st[N]; // ture: 热帖
PII record[N];

int main() {
    
    cin >> n >> d >> k;
    
    for (int i = 0; i < n; i ++ ) {
        scanf("%d%d", &record[i].first, &record[i].second);
    }
    
    sort(record, record + n);
    
    // 维护一段区间[j, i]
    for (int i = 0, j = 0; i < n; i ++ ) {
        int id = record[i].second;
        cnt[id] ++ ;
        // while: 时间有可能相距很长
        while (record[i].first - record[j].first >= d) {
            cnt[record[j].second] -- ;
            j ++ ;
        }
        if (cnt[id] >= k) st[id] = true;
    }

    for (int i = 0; i <= 1e5; i ++ ) {
        if (st[i]) cout << i << endl;
    }
    
    return 0;
    
}