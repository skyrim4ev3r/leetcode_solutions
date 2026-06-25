typedef ptrdiff_t isize;

class Solution {
public:
    static int countMajoritySubarrays(const vector<int>& nums, const int target) {
        const isize len = std::ssize(nums);
        int count = 0;

        for (isize i = 0; i < len; i += 1) {
            int freq = 0;
            for (isize j = i; j < len; j += 1) {
                if (nums[j] == target) {
                    freq += 1;
                }

                if (freq > (j - i + 1) / 2) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
