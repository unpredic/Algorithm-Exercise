class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        if (n == 0) return "";
        int l = n - 1, r = n - 1;
        while (l >= 0) {
            while (r >= 0 && s[r] == ' ') r -- ;
            if (r < 0) break;

            l = r;
            while (l >= 0 && s[l] != ' ') l -- ;

            res += s.substr(l + 1, r - l);
            res += " ";

            r = l;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};