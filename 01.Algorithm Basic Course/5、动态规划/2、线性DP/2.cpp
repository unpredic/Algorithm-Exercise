7
3 1 2 1 8 5 6
状态表示f[i]:
	->集合：所有以第i个数结尾的上升子序列	集合(8) =>{8},{3, 8},{1, 8},{1, 2, 8}, {2, 8}
	->属性：MAX（集合当中的长度的最大值）	f[i] = 3

难点：用倒数第二个数来分类


//状态表示f[i]:
//  ->集合:以i结尾的子序列集合
//  ->属性:MAX(集合中的子序列长度最大值)
//状态计算:
//  ->状态划分:以子序列的倒数第二个元素为划分条件

#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    for (int i = 1; i <= n; i ++ ) {
        f[i] = 1;
        for (int j = 1; j < i; j ++ ) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);
    cout << res << endl;
    
    return 0;
}
