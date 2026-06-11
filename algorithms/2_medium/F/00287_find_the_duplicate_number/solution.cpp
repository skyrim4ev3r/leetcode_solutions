class Solution {
public:
    static int findDuplicate(vector<int>& nums) {
        const ptrdiff_t len = std::ssize(nums);
        assert(len > 0);

        for (ptrdiff_t i = 0; i < len ; i += 1) {
            assert(abs(nums[i]) - 1 >= 0 && abs(nums[i]) - 1 < len);
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            } else {
                for (ptrdiff_t j = 0; j < i; j += 1) {
                    nums[abs(nums[j]) - 1] *= -1;
                }

                return nums[i];
            }
        }

        cerr << "Error: no duplicate found\n";
        abort();
    }
};
