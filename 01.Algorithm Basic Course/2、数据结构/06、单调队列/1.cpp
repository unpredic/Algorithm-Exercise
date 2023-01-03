// 思路：使用单调队列实现
// 以找窗口中最小值为例
// 1.判断队头是否在窗口内部，如果不在队头出队
// 2.循环判断队尾元素是否大于当前元素，如果大于队尾出队
// 3.把当前元素加入队尾
// 注意：队列里存的是该元素在原数组里的序号(0,1,2,3...)


#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int q[N], hh, tt;
int a[N];

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    hh = 0, tt = -1;
    
    for (int i = 0; i < n; i ++ ) {
        
        //判断队头是否在窗口内部,不在就弹出队列维持窗口大小为k
        //i - q[hh] + 1:当前滑动窗口的大小
        if (hh <= tt && i - q[hh] + 1 > k) hh ++ ;
        
        //队尾元素是否大于等于当前元素
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        
        //把当前元素加入队尾
        q[ ++ tt] = i;
        
        //输出队头
        //i+1:
        if (i + 1 >= k) cout << a[q[hh]] << " ";
        
    }
    
    cout << endl;
    
    hh = 0, tt = -1;
    
    for (int i = 0; i < n; i ++ ) {
        
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;
        
        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        
        q[ ++ tt] = i;
        
        if (i >= k - 1) cout << a[q[hh]] << " ";
        
    }
    
    return 0;
}