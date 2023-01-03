// 思路：枚举回文数、判断是否在范围内、判断日期是否合法

#include <iostream>

using namespace std;

int date1, date2;
int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int reverse_num(int x) {
    int res = 0;
    while (x) {
        int t = x % 10;
        res = res * 10 + t;
        x /= 10;
    }
    return res;
}

bool isLeapYear(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

int main() {
    cin >> date1 >> date2;
    int start = date1 / 10000;
    int end = date2 / 10000;
    
    int res = 0;
    
    for (int i = start; i <= end; i ++ ) {
        int month = reverse_num(i % 100);
        int day = reverse_num(i / 100);
        if (month >= 1 && month <= 12) {
            if (isLeapYear(i)) {
                if (month == 2) {
                    if (day >= 1 && day <= 29) res ++ ;
                } else {
                    if (day >= 1 && day <= mth[month]) res ++ ;
                }
            } else {
                if (day >= 1 && day <= mth[month]) res ++ ;
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}



// 思路：枚举回文数、判断是否在范围内、判断日期是否合法

#include <iostream>

using namespace std;

int date1, date2;
int mth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_valid(int x) {
    int year = x / 10000;
    int month = x / 100 % 100;
    int day = x % 100;
    
    if (!month || !day || month > 13) return false;
    
    if (month != 2 && day > mth[month]) return false;
    
    if (month == 2) {
        bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
        if (day > 28 + leap) return false;
    }
    return true;
}

int main() {
    cin >> date1 >> date2;
    
    
    int res = 0;
    
    for (int i = 0; i < 10000; i ++ ) {
        int x = i, r = i;
        for (int j = 0; j < 4; j ++ ) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        
        if (r >= date1 && r <= date2 && check_valid(r)) res ++ ;
        
    }
    
    cout << res << endl;
    
    return 0;
    
}