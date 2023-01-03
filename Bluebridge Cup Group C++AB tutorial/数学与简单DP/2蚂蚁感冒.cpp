#include <iostream>

using namespace std;

const int N = 60;

int n;
int x[N];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++ ) scanf("%d", &x[i]);
    
    //这里left表示左边蚂蚁向右走的数量，right表示右边蚂蚁向左走的数量
    int left = 0, right = 0;
    for (int i = 1; i < n; i ++ ) {
        if (abs(x[i]) < abs(x[0]) && x[i] > 0) left ++ ;
        if (abs(x[i]) > abs(x[0]) && x[i] < 0)  right ++ ;
    }
    
    if (x[0] > 0 && right == 0 || x[0] < 0 && left == 0) puts("1");
    else printf("%d\n", left + right + 1);
    
    return 0;
    
}