class Solution {
public:
    static vector<int> shortestToChar(const string& s, char c) {
        const size_t len{s.size()};
        vector<int> res(len, numeric_limits<int>::max());
        int last_pos{-1};

        for (size_t i{0}; i < len; ++i) {
            if (s[i] == c) {
                last_pos = static_cast<int>(i);
            }

            if (last_pos != -1) {
                res[i] = static_cast<int>(i) - last_pos;
            }
        }

        last_pos = -1;
        for (size_t i{len - 1}; i < len; --i) {
            if (s[i] == c) {
                last_pos = static_cast<int>(i);
            }

            if (last_pos != -1) {
                res[i] = std::min(res[i], last_pos - static_cast<int>(i));
            }
        }

        return res;
    }
};
