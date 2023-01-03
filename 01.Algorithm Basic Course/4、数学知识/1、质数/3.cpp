#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt; // 存所有质数   
bool st[N]; //当前数有没有被筛过

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] * i <= n; j ++ ) {
            // primes[j]是primes[j]*i的最小质因子
            //对于任意一个合数x，假设pj为x最小质因子，当i<x/pj时，一定会被筛掉
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
            /*
            1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子
            */
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    get_primes(n);
    
    cout << cnt << endl;
    
}