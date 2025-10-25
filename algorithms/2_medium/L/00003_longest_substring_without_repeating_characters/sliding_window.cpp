class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        const size_t len = s.size();
        size_t last_seen_index[128];
        std::fill(last_seen_index, last_seen_index + 128, len);

        size_t max_len{0};
        size_t left{0};

        for (size_t right{0}; right < len; ++right) {

            size_t char_index = static_cast<size_t>(s[right]);

            if (last_seen_index[char_index] < len) {
                left = max(left, last_seen_index[char_index] + 1);
            }

            last_seen_index[char_index] = right;

            max_len = max(max_len, right - left + 1);
        }

        return static_cast<int>(max_len);
    }
};
