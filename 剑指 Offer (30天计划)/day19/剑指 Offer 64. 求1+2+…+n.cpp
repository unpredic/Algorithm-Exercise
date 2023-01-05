// 本题需要实现 “当 n=1n = 1n=1 时终止递归” 的需求，可通过短路效应实现。
// n > 1 && sumNums(n - 1) // 当 n = 1 时 n > 1 不成立 ，此时 “短路” ，终止后续递归

// 逻辑运算符的短路效应：
// if(A && B)  // 若 A 为 false ，则 B 的判断不会执行（即短路），直接判定 A && B 为 false
// if(A || B) // 若 A 为 true ，则 B 的判断不会执行（即短路），直接判定 A || B 为 true

class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1) > 0;
        res += n;
        return res;
    }
};