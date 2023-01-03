// 二分：和以往模板不太一样
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + j >> 1;
            if (nums[mid] != mid) j = mid - 1;
            else i = mid + 1;
        }
        return i;
    }
};