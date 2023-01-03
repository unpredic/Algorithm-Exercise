class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, s = 0;
        for (auto x : nums) {
            if (s < 0) s = 0;
            s += x;
            res = max(res, s);
        }
        return res;
    }
};