class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;
        int minv = INT_MAX, res = 0;
        for (int i = 0; i < n; i ++ ) {
            minv = min(minv, prices[i]);
            res = max(res, prices[i] - minv);
        }
        return res;
    }
};