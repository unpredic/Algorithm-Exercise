// 排序, 取前k个即可
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 0; i < k; i ++ ) {
            res.push_back(arr[i]);
        }
        return res;
    }
};

// 快排
class Solution {
public:
    void quick_sort(vector<int>& arr, int l, int r, int k) {
        if (l >= r) return;
        int x = arr[l + r >> 1];
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i ++ ; while (arr[i] < x);
            do j -- ; while (arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        if (j - l + 1 >= k) quick_sort(arr, l, j, k);
        else quick_sort(arr, j + 1, r, k - (j - l + 1));
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr, 0, arr.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < k; i ++ ) {
            res.push_back(arr[i]);
        }
        return res;
    }
};