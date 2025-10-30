class Solution {
    string RLE(const string &s) {

        size_t len{s.size()};
        size_t start{0};
        size_t end{0};
        string res{};

        while (end < len) {
            while (end < len && s[start] == s[end]) {
                end += 1;
            }
            res += to_string(end - start);
            res.push_back(s[start]);
            start = end;
        }  

        return res;
    }
public:
    string countAndSay(int n) {
        string res{"1"};

        for (int i{2}; i <= n; ++i) {
            res = RLE(res);
        }

        return res;
    }
};
