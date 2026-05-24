class Solution {
    static string rle(const string &s) {
        const size_t len = s.size();
        size_t left = 0;
        size_t right = 0;
        string res;
        res.reserve(1 + len * 2);

        while (right < len) {
            while (right < len && s[left] == s[right]) {
                right += 1;
            }
            res += to_string(right - left);
            res.push_back(s[left]);
            left = right;
        }

        return res;
    }
public:
    static string countAndSay(const int n) {
        string res = "1";

        for (int i = 1; i < n; ++i) {
            res = rle(res);
        }

        return res;
    }
};

