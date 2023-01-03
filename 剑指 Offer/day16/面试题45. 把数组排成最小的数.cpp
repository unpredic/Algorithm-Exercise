class Solution {
public:
    static bool myCmp(int &a, int &b) {
        if (to_string(a) + to_string(b) < to_string(b) + to_string(a)) return true;
        else return false;
    }
    string minNumber(vector<int>& nums) {
        string str;
        sort(nums.begin(), nums.end(), myCmp);
        for (auto num: nums) {
            str += to_string(num);
        }
        return str;
    }
};