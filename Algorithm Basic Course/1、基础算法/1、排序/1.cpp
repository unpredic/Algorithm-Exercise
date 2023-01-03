//双指针法、基于分治
//1、确定分界点 x = q[l]、q[r]、q[l + r >> 1](也可取随机一个点)、x不一定在中间
//2、调整区间、使所有小于等于x的在左半边、所有大于等于x的在右半边
//3、递归处理左右两边
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

void quick_sort(int q[],int l,int r){
    if (l >= r) return ;
    
    int x = q[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j){
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i],q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q,j + 1, r); 
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    
    quick_sort(q, 0, n - 1);
    
    for (int i = 0; i < n; i ++ ) cout << q[i] << " ";
    
    return 0; 
}