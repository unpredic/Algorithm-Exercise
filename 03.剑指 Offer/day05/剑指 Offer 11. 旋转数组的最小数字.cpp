// 二分法：可将线性级别的复杂度将为对数级别
class Solution {
public:
    // 旋转次数为1-n，不要忘记处理数组完全单调的特殊情况
    // 二分条件：numbers[i]>=numbers[0]
    // 最后几个数如果和numbers[0]相等需要去除, 不满足二分条件
    int minArray(vector<int>& numbers) {
        int n = numbers.size() - 1;
        // 去除最后几个不满足二分条件的数
        while (n > 0 && numbers[0] == numbers[n]) n -- ;
        // 处理完全单调的特殊情况
        if (numbers[0] <= numbers[n]) return numbers[0];
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (numbers[mid] < numbers[0]) r = mid;
            else l = mid + 1;
        }
        return numbers[l];
    }
};