// 二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return 0;
        else {
            int i = 0, j = nums.size() - 1;
            while (i < j) {
                int mid = i + j + 1 >> 1;
                if (nums[mid] <= target) i = mid;
                else j = mid - 1;
            }
            return i - l + 1;
        }
    }
};