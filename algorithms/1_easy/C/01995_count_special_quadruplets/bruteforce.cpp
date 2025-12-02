class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const size_t n{nums.size()};
        int count{0};

        for (size_t d{n - 1}; d < n; --d) {
            for (size_t c{d - 1}; c < d; --c) {
                for (size_t b{c - 1}; b < c; --b) {
                    for (size_t a{b - 1}; a < b; --a) {
                        if (nums[d] == nums[a] + nums[b] + nums[c]) {
                            count += 1;
                        }
                    }
                }
            }
        }

        return count;
    }
};
