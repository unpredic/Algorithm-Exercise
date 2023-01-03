// 判断质数、分解质因数都有优化版

// 质数：在大于1的自然数（2、3、4....）中，如果只包含1和本身这两个约数，就被称为质数，或者素数（老版本叫法）。
// 1.质数的判断--试除法(暴力、优化)
// 暴力
bool is_prime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i < n; i ++ ) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
    
}

// 优化	
// 一个数的因数都是成对出现的：例如12的因数有3和4,2和6
// 所以我们可以只枚举较小的那一个，即根号n，假设较小的为d(因为i从2开始枚举)，较大的为n/d；
// 则有d <= n/d, 即d <= sqrt(n);
// (i <= sqrt(n))->效率低
// (i * i <= n)->有溢出风险
bool is_prime(int n) {
    if (n < 2) return false;
    
    for (int i = 2; i <= n / i; i ++ ) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
    
}

// 2.分解质因数--试除法
// 思路：从小到大枚举所有数
// 质因数就是一个数的约数,并且是质数.
// 比如8=2×2×2,2就是8的质因数;
// 12=2×2×3,2和3就是12的质因数.
// 把一个式子以12=2×2×3的形式表示,叫做分解质因数.
// 分解质因数只针对合数,分解质因数的方法是先用一个合数的最小质因数去除这个合数,
// 得出的数若是一个质数,就写成这个合数相乘形式;
// 若是一个合数就继续按原来的方法,直至最后是一个质数

// 暴力
void divide(int x) {
    for (int i = 2; i <= n; i ++ ) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s ++ ;
            }
            cout << i << " " << s << endl;
        }
    }
}

// 优化
// 小技巧：n中最多只包含一个大于sqrt(n)的因子
// 证：假设有两个，那这两个相乘就一定大于n了
void divide(int x) {
    // 先枚举出小于sqrt(n)的因子
    for (int i = 2; i <= n / i; i ++ ) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s ++ ;
            }
            cout << i << " " << s << endl;
        }
    }
    // 单独处理最后一个大于sqrt(n)的因子
    if (n > 1) {
        cout << n << " " << 1 << endl;
    }
}

//  3.晒质数
//  朴素晒法：
//  10   ->      2,3,4,5,6,7,8,9,10
//  2-> 4,6,8,10
//  3-> 6,9
//  4-> 8
//  5-> 10
//  6-> 
//  7->
//  一步步筛选
//  o(nlog n)
void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++ ]  = i;
        }
        
        for (int j = i + i; j <= n; j += i) {
            st[j] = true;
        }
    }
}

//  优化版 (埃氏筛法)
//  10   ->      2,3,4,5,6,7,8,9,10
//  2-> 4,6,8,10
//  3-> 6,9
//  5-> 10
//  7->
//  只需要筛选质数
//  质数定理：1 ~ n 中有n/lg n 个质数
//  o(nlog(log n))
void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++ ]  = i;
            for (int j = i + i; j <= n; j += i) {
                st[j] = true;
            }
        }
    }
}

//  线性筛法
//  只有一个质因子的正整数为质数.
//  1没有质因子。
//  5只有1个质因子，5本身。（5是质数。）
//  6的质因子是2和3。(6 = 2×3)
//  2、4、8、16等只有1个质因子：2（2是质数，4 = 22，8 = 23，如此类推。）
//  10   ->      2,3,4,5,6,7,8,9,10
//  2 -> 4  primes[] = {2}
//  3 -> 6 -> 9 primes[] = {2, 3}
//  4 -> 8
//  5 -> 10
//  primes[] = {2}
//  i = 2时, primes[0] = 2; 
//  for j = 0; primes[j]=2 <= 10/2; j ++
//      st[2 * 2] = true;
//      if (2 % 2 == 0) break;
//  i = 3时, primes[0] = 2, primes[1] = 3;
//  for j = 0; primes[0] = 2 <= 10 / 3; j ++ 
//      st[2 * 3] = true;
//      if (3 % 2 == 0) break;
//  for j = 1; primes[1] = 3 <= 10 / 3; j ++
//      st[3 * 3] = true;
//      if (3 % 3 == 0) break;
//  i = 4时, primes[0] = 2, primes[1] = 3;
//  for j = 0; primes[j] = 2 <= 10 / 2; j ++ 
//      st[2 * 4] = true;
//      if (4 % 2 == 0) break;
void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}