class Solution {
    static inline int rev_digits(int num) {
        int rev{ 0 };
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, size_t> seen{};
        size_t min_abs_diff{ numeric_limits<size_t>::max() };

        for (auto it{ nums.crbegin() }; it !=  nums.crend(); ++it) {
            const size_t index{ static_cast<size_t>(it - nums.crbegin()) };
            const int rev{ rev_digits(*it) };
            const auto& find{ seen.find(rev) };

            if (find != seen.end()) {
                min_abs_diff = std::min(min_abs_diff, index - find->second);
            }

            seen[*it] = index;
        }

        if (min_abs_diff == numeric_limits<size_t>::max()) {
            return -1;
        }

        return static_cast<int>(min_abs_diff);
    }
};
