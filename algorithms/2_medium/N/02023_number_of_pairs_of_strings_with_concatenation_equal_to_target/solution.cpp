class Solution {
    static inline bool are_lefthalf_righthalf_same(const string& word) {
        if (word.size() % 2 == 1) {
            return false;
        }

        const size_t half {word.size() / 2};

        for (size_t i {0}; i < half; ++i) {
            if (word[i] != word[i + half]) {
                return false;
            }
        }

        return true;
    }
public:
    static int numOfPairs(const vector<string>& nums, const string& target) {
        const size_t target_len {target.size()};
        const bool lefthalf_righthalf_are_same {are_lefthalf_righthalf_same(target)};
        vector<int> counts_starts_with(target_len, 0);
        vector<int> counts_ends_with(target_len, 0);
        int count {0};

        for (const auto& num : nums) {
            if (num.size() < target_len) {
                if (target.starts_with(num)) {
                    counts_starts_with[num.size()] += 1;
                }

                if (target.ends_with(num)) {
                    counts_ends_with[num.size()] += 1;
                }
            }
        }

        for (size_t i {1}; i < target_len; ++i) {
            if (lefthalf_righthalf_are_same && i == target_len - i) {
                count += (counts_starts_with[i] - 1) * (counts_ends_with[target_len - i]);
            } else {
                count += counts_starts_with[i] * counts_ends_with[target_len - i];
            }
        }

        return count;
    }
};
