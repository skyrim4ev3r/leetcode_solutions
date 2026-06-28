typedef ptrdiff_t isize;

class Solution {
    static inline int count_pairs(const vector<int>& nums1, const vector<int>& nums2) {
        const isize len = std::ssize(nums1);
        auto map = unordered_map<int64_t, int>();
        int res = 0;

        for (const int num : nums1) {
            map[num] += 1;
        }

        for (const int num : nums2) {
            const int64_t sq = static_cast<int64_t>(num) * num;

            for (const auto [val, freq] : map) {
                if (sq % val == 0) {
                    const int other = (sq / val);
                    if (other == val) {
                        res += freq * (freq - 1) / 2; 
                    } else if (other > val) {
                        const auto it = map.find(other);
                        if (it != map.end()) {
                            res += freq * (it->second);
                        }
                    }
                }
            }
        }

        return res;
    }

public:
    static int numTriplets(const vector<int>& nums1, const vector<int>& nums2) {
        return count_pairs(nums1, nums2) + count_pairs(nums2, nums1);
    }
};
