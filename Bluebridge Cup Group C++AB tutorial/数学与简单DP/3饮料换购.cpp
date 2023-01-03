#include <iostream>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    
    int res = n;
    while (n >= 3) {
        int x = n % 3;
        n /= 3;
        res += n;
        n += x;
    }
    
    printf("%d\n", res);
    
    return 0;
    
}