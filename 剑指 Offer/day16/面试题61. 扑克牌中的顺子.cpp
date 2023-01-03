class Solution {
public:
    // 除大小王外，所有牌 无重复
    // 设此 555 张牌中最大的牌为 max ，最小的牌为 min （大小王除外），则需满足：max - min < 5
    bool isStraight(vector<int>& nums) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i ++ ) {
            if (nums[i] == 0) cnt ++ ;
            else if (nums[i] == nums[i + 1]) return false;
        }
        return nums[4] - nums[cnt] < 5;
    }
};