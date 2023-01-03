#include <iostream>

using namespace std;

int mth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int x) {
    int year = x / 10000;
    int month = x / 100 % 100;
    int day = x % 100;
    
    if (!day || !month || month > 12) return false;
    if (month != 2 && day > mth[month]) return false;
    if (month == 2) {
        int leap = year % 400 == 0 || year % 100 && year % 4 == 0;
        if (day > 28 + leap) return false;
    }
    return true;
}

int main() {
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    
    for (int i = 19600101; i <= 20591231; i ++ ) {
        int x = i;
        if (check_valid(x)) {
            int year = x / 10000 % 100;
            int month = x / 100 % 100;
            int day = x % 100;
            if (a == year && b == month && c == day || 
                a == month && b == day && c == year || 
                a == day && b == month && c == year) {
                printf("%d-%02d-%02d\n", x / 10000, x / 100 % 100, x % 100);
            }
        }
    }
    return 0;
}